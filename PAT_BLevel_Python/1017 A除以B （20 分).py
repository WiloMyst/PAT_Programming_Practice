A, B = tuple(map(int, input().split()))
print(str(A//B)+' '+str(A%B))
# input()函数接收任意"整行"输入，将所有输入默认为字符串处理，并返回字符串类型
# split()可以根据分隔符拆解成子串组成的list，格式split('分隔符'，分割次数)
# int()函数用于将一个字符串或数字转换为整型
# map()把函数f依次作用在list(可迭代对象)的每个元素上，得到一个新的list并返回
# tuple(list)将列表转化为元组。(这里不用转tuple也可以)
# 多重赋值：A, B = 列表/元组
# print("默认换行")  print("不换行打印",end="")  print("以竖线结尾打印",end="|\n")