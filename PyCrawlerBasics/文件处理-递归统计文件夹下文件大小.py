import os
import time

start = time.time()

def size_dir(abs_dir):
    if not os.path.exists(abs_dir):
        print(abs_dir,'文件不存在，无法统计')
        return None
    size = 0
    if os.path.isfile(abs_dir):
        size = os.path.getsize(abs_dir)       
    if os.path.isdir(abs_dir):       
        files_name = os.listdir(abs_dir)
        temp_dir = abs_dir
        for file_name in files_name:
            abs_dir = temp_dir + "\\" + file_name
            size += size_dir(abs_dir)
    return size
        
file_dir = input("请输入待统计大小的文件路径：")
abs_dir = os.path.abspath(file_dir)
print("文件夹文件大小为：{}".format(
    size_dir(abs_dir)))

print("cost time of recursion: {}".format(time.time() - start))
#print(os.path.getsize(file_dir))
