# Your code goes here
xx = [1,2,3,4,5,6,7,8]
xx_reversed = []
yy = []

for element in xx:
    xx_reversed = xx.insert(0,element)

print(xx_reversed)

for i in range(len(xx)):
    pair = (xx[i],xx_reversed[i])
    yy = yy.append(pair)

print(yy)
