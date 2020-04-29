import json
import csv

num_year_dict = {}
sum_year_dict = {}
ave_year_dict = {}

csvfile = open("徐克.csv","wt",newline = "",encoding = "utf-8-sig")
xuke = csv.writer(csvfile,delimiter = ",")
header = ["电影编号","电影名称","上映年份","评分","导演姓名"]
xuke.writerow(header)
with open("movieList.txt","rt",encoding = "utf-8-sig") as fo:
    for line in fo:
        movie_info = json.loads(line)#转前转后都是dict，只不过转成python编码类型
        directors = movie_info["Director"]
        movie_directors = []
        for director in directors:
            star = director["StarName"]
            movie_directors.append(star)
        if "徐克" in movie_directors:
            xuke_list = [movie_info["MovieID"],movie_info["MovieName"],movie_info["MovieYear"],movie_info["MovieScore"],"、".join(movie_directors)]
            xuke.writerow(xuke_list)
csvfile.close()
print("finished")
            

