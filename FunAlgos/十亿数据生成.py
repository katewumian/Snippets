import random
fw = open("data.txt","wt",encoding = 'utf-8')
interator = (str(random.randint(0,999999999)) for i in range(1000000000))
for integer in interator:
    fw.write(integer + ' ')
fw.close()
