import requests
from bs4 import BeautifulSoup


temp_url = "http://en.people.cn/business/index{}.html"
for i in range(20):
    r = requests.get(temp_url.format(i + 1))
    r.encoding = r.apparent_encoding
    soup = BeautifulSoup(r.text,"html.parser")
    news = soup.find_all("div",{"class":"d2_17 clear"})  #如果是find则返回的类型为Tag，这里为resultset类型
    for item in news:
        print(item.a.string,"\t",item.find("span").contents[0])
