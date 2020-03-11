# -*- coding: UTF-8 -*- 
def move(n, a, b, c):
    # 如果移动次数为0，直接退出
    if n == 0:
        return
    
    # 如果移动次数为1，此时不需要把
    # a移到b上，可以直接从a移到c
    if n == 1:
        print("%s --> %s" % (a, c))
        return
    
    # 如果移动次数为2及以上
    # 先把一个盘子从a移到b上
    print("%s --> %s" % (a, b)) 

    # 再把剩下的n-1个盘子从a移到c上
    move(n-1, a, b, c)

    # 再把b上的盘子移到c上
    print("%s --> %s" % (b, c))

# move(4, 'A', 'B', 'C')

def greet(name=None):
    # 如果name有值传进来
    if name: 
        print("Hello " + name)
    else:
        print("Hello World")

greet()
greet("Kaylee")