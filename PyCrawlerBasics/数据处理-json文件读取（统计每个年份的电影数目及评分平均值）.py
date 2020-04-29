import json
num_year_dict = {}
sum_year_dict = {}
ave_year_dict = {}
with open("movieList.txt","rt",encoding = "utf-8-sig") as fo:
    for line in fo:
        movie_info = json.loads(line)#转前转后都是dict，只不过转成python编码类型
        movie_year = movie_info["MovieYear"]  #dict允许int类型
        movie_score = movie_info["MovieScore"]
        num_year_dict[movie_year] = num_year_dict.get(movie_year,0) + 1
        sum_year_dict[movie_year] = sum_year_dict.get(movie_year,0) + movie_score
for key,value in num_year_dict.items():
    ave_year_dict[key] = sum_year_dict[key]/num_year_dict[key]

ave_list = list(ave_year_dict.items())
ave_list.sort(key = lambda item:item[0],reverse = True)

for item in ave_list:
    print(item[0],",",num_year_dict[item[0]],",",item[1])
    
