import requests
from bs4 import BeautifulSoup

r = requests.get("https://www.dlut.edu.cn")
r.encoding = r.apparent_encoding
soup = BeautifulSoup(r.text,"html.parser")

result = soup.find_all("a",{"class":"c50255"})
for alink in result:
    print(alink.attrs["title"],alink.attrs["href"])
