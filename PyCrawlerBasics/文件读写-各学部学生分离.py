# 将所有学生读取出来存储在dept_dict字典结构中，然后统一输出到不同文件中
# 当文件过大时，此方法无法处理

dept_dict = {}  # {key=学部，value=[line,line]}
with open("选课名单.csv", "rt") as fo:
    header = fo.readline()
    for line in fo:
        splits = line.replace("\n","").split(",")
        dept = splits[4]
        if dept in dept_dict:
            dept_dict[dept].append(line)
        else:
            dept_dict[dept] = [line]

for dept,dept_stus in dept_dict.items():
    with open(dept + ".txt","wt") as fw:
        fw.write(header)
        for line in dept_stus:
            fw.write(line)

