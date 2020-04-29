import requests
def getHTMLText(url):
    
        r = requests.get(url,timeout = 30)
        r.raise_for_status()
        r.encoding = 'utf-8'
        print(r.text)
        return r.text
   
#user_url = input("Please enter a URL:")
user_url = "https://so.gushiwen.org/authors/authorvsw_9cb3b7c0e4a0A1.aspx"

fw = open("lqz.txt","wt",encoding = "utf-8")
lqz_splits = user_url.split("A1")
for count in range(11):
    lqz = getHTMLText(lqz_splits[0] + "A" + str(count + 1) + lqz_splits[1])
    # print(lqz)
    fw.writelines(lqz)
fw.close()
