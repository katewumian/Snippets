import requests
def getHTMLText(url):
    try:
        r = requests.get(url,timeout = 30)
        r.raise_for_status()
        r.encoding = 'utf-8'
        return r.text
    except:
        return ""
#user_url = input("Please enter a URL:")
user_url = "http://www.baidu.com"
tt = getHTMLText(user_url)
print(type(tt))
fw = open("baidu_crawler.txt","wt",encoding = "utf-8")
fw.writelines(tt)
fw.close()
