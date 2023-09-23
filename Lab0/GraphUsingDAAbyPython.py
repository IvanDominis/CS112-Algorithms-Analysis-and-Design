import numpy as np
def check(l,x,y):
    if l[x][y]==1:
        return 1
    return 0
def solve(l,x,v):
    rs = []
    d = 0
    for i in range(v):
        if l[x][i]==1:
            print(i+1, end=' ')
            d=1
    if d==1: print('',end='\n')
    if d==0:
        print('NONE')
    
# InputGraph
l =[]
l = list(map(int,input().split()))
v,e,n= l[0],l[1],l[2]
g = np.zeros((v,v))
for i in range(e):
    d=[]
    d=list(map(int,input().split()))
    x,y=d[0],d[1]
    g[x-1][y-1]=1
# Process
t = []
for i in range(n):
    t.append(list(map(int,input().split())))
for i in range(n):
    x = t[i][1]-1
    if t[i][0]==1:
        y = t[i][2]-1
        if check(g,x,y)==1:
            print('TRUE')
        else: 
            print('FALSE')
    else:
        solve(g,x,v)



