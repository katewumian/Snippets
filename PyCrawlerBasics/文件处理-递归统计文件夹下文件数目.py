import os
num = 0
def num_dir(file_dir,num):
    dir_name = os.path.abspath(file_dir)
    if not os.path.exists(dir_name):
        print(file_dir,'文件不存在，无法统计')
        return None
    if os.path.isfile(dir_name):
        num += 1    
    files = os.listdir(dir_name)
    for file in files:
        abs_file = dir_name + "\\" + file
        if os.path.isdir(abs_file):
            num = num_dir(abs_file,num)
        elif os.path.isfile(abs_file):
            num += 1
    return num
        
file_dir = input("请输入要统计的路径：")
print("文件夹文件个数：{}".format(num_dir(file_dir,num)))
