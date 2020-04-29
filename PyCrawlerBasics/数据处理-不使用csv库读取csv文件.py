fo = open("歌曲.csv","rt",encoding = "utf-8")
fw = open("new.txt","wt",encoding = "utf-8")
#fw1 =open("new1.txt","wt",encoding = "utf-8")
header = fo.readline()
fw.write(header)#没有writeline属性
#fw1.write(header)
for line in fo:
    line_times = line.replace("次\n","").split(",")#replace和split并不会改变原来的字符串
    if int(line_times[3]) > 1500:
        fw.write(line)
#    else:
#        fw1.write(line)
fw.close()
print("finished")
#fw1.close()
        
