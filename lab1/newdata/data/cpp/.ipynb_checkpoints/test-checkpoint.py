import pandas as pd

frame = pd.read_csv('/home/pyton/Downloads/data/cpp/test.csv', sep=';')
frame = frame.sample(frac=1)
train_data = frame[:75]
test_data = frame[-25:]

x_train = train_data.iloc[:,0:2]
y_train = train_data.iloc[:,2:3]

x_test = test_data.iloc[:,0:2]
y_test = test_data.iloc[:,2:3]
from matplotlib import pyplot
import numpy as np

x1= []
x2=[]
print(len(frame))
for i in range(len(frame)):
    if(frame.iloc[i][2] == 1.0):
        x1.append(frame.iloc[i])
    else:
        x2.append(frame.iloc[i])
x1 = np.array(x1)
print(len(x2))
r = range(len(x1))
xf,xs,yf,ys = [],[],[],[]
for i in r:
    xf.append(x1[i][0])
    xs.append(x1[i][1])
    yf.append(x2[i][0])
    ys.append(x2[i][1])


pyplot.scatter(xf,xs,marker='+')
pyplot.scatter(yf,ys,c='green',marker='o')
import numpy as np

def actiation(w,x):
    theta = 0.5
    res = np.dot(w,x)
    if res >=  0.6:
        return 1
    else:
        return 0
def update(w,x,y,d):
        new_w = [0,0,0]
        #print(str(x)+' '+str(w)+' '+str(y)+str(d))
        for k in range(len(w)):
            new_w[k] = w[k] + 0.1*(d-y)*x[k]
        return new_w
y = []
w = [0,0,0]

for i in range(75):
    x = []
    x.append(1)
    for j in x_train[:i+1].values.tolist()[i]:
        x.append(j)
    y.append(actiation(w,x))
    w = update(w,x,y[i],y_train[:i+1].values.tolist()[i][0])


y=[]
for i in range(25):
    x = []
    x.append(1)
    for j in x_test[:i+1].values.tolist()[i]:
        x.append(j)
    y.append(actiation(w,x))

y_real = y_test[:].values.tolist()
count = 0
for i in range(len(y)):
    if y[i] == y_real[i][0]:
        count+=1
print(count*1.0/len(y))
pyplot.scatter(xf,xs,marker='+')
pyplot.scatter(yf,ys,c='green',marker='o')
f = []
for x in np.arange(0,1,0.1):
    f.append(actiation(w,[1,x,x]))
pyplot.plot(np.arange(0,1,0.1),f, color='red')
print(w)