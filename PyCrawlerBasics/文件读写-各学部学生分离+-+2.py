# 将不同学部的文件对象存放在字典中，随读随存，可以解决文件过大的问题

file_dict = {}  # {key 学部名称 : value 文件对象}

with open("选课名单.csv", "rt") as fo:
    header = fo.readline()
    for line in fo:
        splits = line.replace("\n","").split(",")
        dept = splits[4]

        if dept in file_dict:
            fw = file_dict[dept]
        else:
            fw = open(dept+".txt", "wt")
            file_dict[dept] = fw

        fw.write(line)


print(file_dict)
for dept,file in file_dict.items():
    file.close()
















##   dept_flag = set()
##   
##        if not dept in dept_flag:
##            fw.write(header)
##            dept_flag.add(dept)
        
