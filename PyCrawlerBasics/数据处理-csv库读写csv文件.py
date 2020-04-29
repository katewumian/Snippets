import csv
count = 0
with open("歌曲.csv","rt",newline = "", encoding = "utf-8") as csvfile:#with打开方式要注意缩进
    reader = csv.reader(csvfile,delimiter = ',')#用csv的好处就是直接把对象读成list格式（每个item为str格式）
    with open("_new.csv","wt",newline = "",encoding = "utf-8") as _csvfile:
        writer = csv.writer(_csvfile,delimiter = ",")#csv的格式控制在这里控制
        header = next(reader)#读取首行的方法
        writer.writerow(header)
        for line in reader:#此行一定要缩进，不然会报错——在一个已关闭的文件上操作
            line_rep = line[3].replace("次","")
            if eval(line_rep) > 1500:
                writer.writerow(line)#csv的写：writerow()，只要传递一个list即可，而且更可以是从reader来的各个row的格式
            else:
                count += 1
print(count)
            

