import bisect
a=[-1,0,0,1,1,1,1,1,3]
# x=bisect.bisect_left(l,1)
# print(x)
# x=bisect.bisect_right(l,1)
# print(x)
i=0
l=0
h=len(a)-1
t=1
while(l<=h):
    m=(l+h)//2
    if a[m]<=t:
        l=m+1
    else:
        h=m-1
print(l,h)
        