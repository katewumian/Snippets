import os
import time

start = time.time()

# 同一层的文件夹都先存到temp_list里

file_dir = input("请输入文件路径：")
#print(os.path.getsize(file_dir))
total = 0
abs_dir = os.path.abspath(file_dir)
#print(os.path.getsize(abs_dir))
file_list = []

file_list.append(abs_dir)
#print(type(file_list))
#print(type(abs_dir))

while file_list:
    abs_dir = file_list.pop()
    if os.path.isfile(abs_dir):
        total += os.path.getsize(abs_dir)
#        print(os.path.getsize(abs_dir))
#        print(total)
        continue
    if os.path.isdir(abs_dir):
        abs_dir_temp = abs_dir
        file_name_list = os.listdir(abs_dir)
        for file in file_name_list:
            abs_dir = abs_dir_temp + "\\" + file
            file_list.append(abs_dir)
#    print(total)


print("文件夹文件大小为：{}".format(total))

print("cost time of no recursion: {}".format(time.time() - start))
