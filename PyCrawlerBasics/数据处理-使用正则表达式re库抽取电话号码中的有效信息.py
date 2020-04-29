import re


# 1. 提取所有11位数字电话号码
with open("data2.txt", "rt", encoding="gbk") as fo:
    for line in fo:
        pattern = r".+(\d{11})"
        result = re.match(pattern,line)
        if result:
            print(result.group(1))

# 2. 提取17或者14开头的电话号码
with open("data2.txt", "rt", encoding="gbk") as fo:
    for line in fo:
        pattern = r".+(1[74]\d{9})"
        result = re.match(pattern,line)
        if result:
            print(result.group(1))
        

# 3. 验证每一行数据都是中文人名+\t+11位电话号码，人名必须是2-3个中文字符
with open("data2.txt", "rt", encoding="gbk") as fo:
    for line in fo:
        pattern = r"[\u4e00-\u9fa5]{2,3}\t\d{11}"
        if re.match(pattern,line):
#            print(re.match(pattern,line).group(0))#match之后没有\n，是因为match不需要考虑尾部
            print(line)
        


# 4. 提取出“王”姓的电话号码，输出：王xx的电话号码是xxxxxxxxxxx
with open("data2.txt", "rt", encoding="gbk") as fo:
    for line in fo:
        pattern = r"(王[\u4e00-\u9fa5]{1,2})\t(\d{11})" #小括号可以使得match后的result具有多个group，从1开始为所需要的
        result = re.match(pattern,line)
        if result:
            print("{}的电话号码是{}".format(result.group(1),result.group(2)))

