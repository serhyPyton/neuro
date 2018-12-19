import pandas as pd
from numpy import genfromtxt

data = genfromtxt('data01.csv', delimiter=';')
for i in data:
    if i[2]==0:
        i[2]=-1
train =(data[0:75,0:3])
test =(data[75:100,0:3])
#print(train)
w1 = 0.5
w2 = 0.5
b  = 0.5
print(w1, w2, b)
def f(x1,x2):
    return(x1*w1+x2*w2+b)
def decision_unit(value):
    return -1 if value < 0 else 1
for i in range(20):
    for it in range(75):
        value=f(train[it][0],train[it][1])
        true_label = train[it][2]
        pred_label = decision_unit(value)
        if (true_label != pred_label):
            w1 = w1 + train[it][0] * 0.5*true_label
            w2 = w2 + train[it][1] * 0.5*true_label
            b = b + 0.5*true_label
    print(w1,w2,b)
