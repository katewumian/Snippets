# 统计各年级学生数目并按学生数目从大到小排序

year_dict = {}
with open("选课名单.csv", "rt") as fo:
    header = fo.readline()
    for line in fo:
        splits = line.replace("\n","").split(",")
        year = splits[1][:4]
        year_dict[year] = year_dict.get(year,0) + 1

# 输出合计数目验证数据是否正确
print(sum([item[1] for item in year_dict.items()]))

year_list = list(year_dict.items())
year_list.sort(key=lambda item:item[0], reverse=True)
for year,count in year_list:
    print(year, count)
