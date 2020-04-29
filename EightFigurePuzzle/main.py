# -*- coding: utf-8 -*-

from Node import Node
import Algorithm

def getStatus(Node):
    reverseOrderNumber = 0#计数
    array2d = Node.array2d
    array = [i for item in array2d for i in item]#列表生成式，把二维数字转化为一维列表
    array.remove(0)#比较大于0的八个数字
    for i in range(0, len(array)):
        for j in range(i, len(array)):
            if array[i]>array[j]:
                reverseOrderNumber += 1
            
    return reverseOrderNumber

def isTransform(startNode,endNode):#用于判断问题是否可解，用到了getStatus函数
    start = getStatus(startNode)
    end = getStatus(endNode)
    
    if start%2 != end%2:
        return False
    
    return True

if __name__ == '__main__':

    #构建初始状态、目标状态
    startNode = Node([[4,8,6],[3,0,7],[2,1,5]])
    endNode = Node([[1,2,3],[4,8,5],[6,7,0]])
    Astar = Algorithm.Astar(startNode,endNode)#将Astar初始化为Algorithm中的Astar类
    
    #判断是否有解
    if isTransform(startNode,endNode) and Astar.start():#如果问题有解则展开A*搜索
        Astar.showPath()#调用showMap函数，把路径显示出来
    else:
        print("无解")







