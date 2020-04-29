import random
rand_list = list([random.randint(0,1000) for i in range(100)])
list_fir = rand_list[:50]
list_sec = rand_list[50:100]
list_fir.sort()
list_sec.sort(reverse = True)
list_sum = list_fir + list_sec
#print(list_sum)
list_sum_str = [str(list_sum[i]) for i in range(100)]
list_str = " ".join(list_sum_str)
print(list_str)
