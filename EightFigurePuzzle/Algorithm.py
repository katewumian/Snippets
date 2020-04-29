# -*- coding: utf-8 -*-

from Node import Node
import copy

def showMap(node):#显示信息——代价值、启发性信息、估价函数（f = g + h），二维数组
    print("代价:",node.g)
    print("启发性信息:",node.h)
    print("估价函数:",node.g+node.h)
    for x in range(0, 3):
        for y in range(0, 3):
            print(node.array2d[x][y], end='')
        print(" ")
    print("--------")
    return

def move(array2d, srcX, srcY, drcX, drcY):#全局函数，将两个位置上的数码互换
    temp = array2d[srcX][srcY]
    array2d[srcX][srcY] = array2d[drcX][drcY]
    array2d[drcX][drcY] = temp
    return array2d

class Astar: 
    
    def __init__(self, startNode, endNode):
        '''
        初始化类Astar对象的7个数据成员
        '''
        #开放列表
        self.openList = []
        #封闭列表  
        self.closeList = []
        #保存最后生成的"路径"
        self.pathList = []
        #寻路起点  
        self.startNode = startNode
        #寻路终点
        self.endNode = endNode 
        #当前处理的节点，初始化时为startNode
        self.currentNode = startNode
        #当前最优步数step（定义实际代价g = self.step）
        self.step = 0
        
    def getMinFNode(self):
        """ 
        获得openList中f(x)最小的节点
        """  
        nodeTemp = self.openList[0]  
        for node in self.openList:  
            if node.g + node.h < nodeTemp.g + nodeTemp.h:  
                nodeTemp = node  
        return nodeTemp

    def nodeInOpenlist(self,node):
        """
        判断节点是否在开放列表
        """
        for nodeTmp in self.openList:  
            if nodeTmp.array2d == node.array2d:  
                return True  #节点在开放列表，返回True
        return False

    def nodeInCloselist(self,node):
        """
        判断节点是否在封闭列表（只判断属性array2d是否相等）
        """
        for nodeTmp in self.closeList:  
            if nodeTmp.array2d == node.array2d:  
                return True  
        return False
       
    def getNodeFromOpenList(self,node):  
        """
        返回节点以获取状态信息（二维数组array,父节点father,代价g,启发h）
        """
        for nodeTmp in self.openList:  
            if nodeTmp.array2d == node.array2d:  
                return nodeTmp  
        return None

    def findOneNode(self,node):#移动后找到一个点的操作
        """ 
        找到下一个节点后，判断是否需要把该节点放入开放列表
        """  
        #忽略封闭列表
        if self.nodeInCloselist(node):  
            return
        #G值计算
        gTemp = self.step
        #如果node不在openList中，就加入openList  
        if self.nodeInOpenlist(node) == False:
            #G值更新
            node.setG(gTemp)
            #H值计算、更新
            hTemp = self.endNode
            node.setH(hTemp)
            #父节点更新
            node.father = self.currentNode
            #将node加入openList
            self.openList.append(node)
        #如果在openList中，比较currentNode到移动后的节点的G和openList中该节点的G值，是否需要更新openList中的节点
        #如果更小，就重新计算g值，并且改变父结点 
        else:
            nodeTmp = self.getNodeFromOpenList(node)#node是移动找到的点，而返回的nodeTmp是openList表中的具有相同二维数组的点
            #修改openList表中的对应节点的属性值
            if gTemp < nodeTmp.g:
                nodeTmp.g = gTemp  
                nodeTmp.father = self.currentNode  
        return

    def searchNear(self):
        """ 
        找到0所在的位置，搜索到下一个可以与0交换的数码
        """ 
        flag = False
        for x in range(0, 3):
            for y in range(0,3):
                if self.currentNode.array2d[x][y] == 0:
                    flag = True
                    break
            if flag == True:
                break

        self.step += 1
        # 深复制，不改变原状态
        # 判断0位置
        if x - 1 >= 0:
            arrayTemp = move(copy.deepcopy(self.currentNode.array2d), x, y, x - 1, y)
            self.findOneNode(Node(arrayTemp))
        if x + 1 < 3:
            arrayTemp = move(copy.deepcopy(self.currentNode.array2d), x, y, x + 1, y)
            self.findOneNode(Node(arrayTemp))
        if y - 1 >= 0:
            arrayTemp = move(copy.deepcopy(self.currentNode.array2d), x, y, x, y - 1)
            self.findOneNode(Node(arrayTemp))
        if y + 1 < 3:
            arrayTemp = move(copy.deepcopy(self.currentNode.array2d), x, y, x, y + 1)
            self.findOneNode(Node(arrayTemp))

        return

    def start(self):
        ''''' 
        开始寻路 
        '''
        #将初始节点加入开放列表
        self.startNode.setH(self.endNode)
        self.startNode.setG(self.step)
        self.openList.append(self.startNode)

        while True:
            #获取当前开放列表里F值最小的节点
            self.currentNode = self.getMinFNode()
            #将结点放入到已经闭合列表
            self.closeList.append(self.currentNode)
            #将结点从开放列表中移除
            self.openList.remove(self.currentNode)
            #从当前节点更新A*当前代价，在下一步移动之后step+1
            self.step = self.currentNode.getG()
            #搜索当前结点可走的路径
            self.searchNear()
            
            #检验是否结束
            if self.nodeInOpenlist(self.endNode):
                nodeTmp = self.getNodeFromOpenList(self.endNode)
                #按照节点记录的father节点，倒推一个一个把路径上的节点加入pathlist，直到某个节点父节点为空
                while True:
                    self.pathList.append(nodeTmp)
                    if nodeTmp.father != None:
                        nodeTmp = nodeTmp.father
                    else:
                        return True
            elif len(self.openList) == 0:
                return False
            elif self.step > 30:
                return False

        return True
    
    def showPath(self):
        '''
        打印找到的从起点到终点的最优的路径
        '''
        for node in self.pathList[::-1]:#逆序
            showMap(node)
    
    
