import jieba
import json

type_dict = {}
type_sum_dict = {}
excludes = open("stop_words.txt","rt",encoding = "utf-8").read()
with open("movieList.txt","rt",encoding = "utf-8") as fo:
    for line in fo:
        movie_info = json.loads(line)
        movie_types = movie_info["MovieTypes"]
        if len(movie_types) == 0:
            continue
        else:
            movie_type = movie_types[0]
            words = jieba.lcut(movie_info["Summary"])
            word_dict = {}
            for word in words:
                if len(word) > 1 and word not in excludes:
                    word_dict[word] = word_dict.get(word,0) + 1
            if movie_type not in type_dict:
                type_dict[movie_type] = [word_dict]
            else:
                type_dict[movie_type].append(word_dict)
           # type_dict[movie_type] = type_dict.get(movie_type,[]).append(word_dict) 不知为何会报错nonetype object has no attribute append,因此改成了上面四行的写法
    for _type,words_dict in type_dict.items():#words:[{"d":2,"a":2},{"ada":3,"ase":4}]
        print(_type)
        word_dict_inner = {}
        for words in words_dict:
            for word in words:
                word_dict_inner[word] = word_dict_inner.get(word,0) + 1
        word_list_inner = list(word_dict_inner.items())
        word_list_inner.sort(key = lambda item:item[1],reverse = True)
        print(word_list_inner[:50])
            


