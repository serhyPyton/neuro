import random
import matplotlib.pyplot as plt
import math

def f(x):
    return -(x**2.-4.*x+3.)/256
    
x = []
y = []
for i in range(-256 * 100, 256 * 100):
    x.append(i / 100.0)
    y.append(f(i / 100.0))
plt.plot(x, y)
plt.show()

x = []
y = []
for i in range(0, 256 * 100):
    x.append(i / 100.0)
    y.append(f(i / 100.0))
plt.plot(x, y)
plt.show()

def normalize(l : list):
    res = []
    s = 0.0
    for i in range(len(l)):
        s = s + l[i]
    for i in range(len(l)):
        res.append(l[i] / abs(s))
    return res      
    
def find_object(l : list, r : float):
    for i in range(len(l)):
        if i == len(l) - 1:
            return i
        if l[i] <= r and r < l[i + 1]:
            return i
            
def hybridization(p1 : int, p2 : int, i1 : int, i2 : int):
    p = 0.75
    r = random.random()
    if r > p:
        return [p1, p2]
    a = p1
    b = p2
    for j in range(i1, i2 + 1):
        if ((p1 >> j) & 1) == 1:
            b = b | (1 << j)
        else:
            b = b & (~(1 << j))
        if ((p2 >> j) & 1) == 1:
            a = a | (1 << j)
        else:
            a = a & (~(1 << j))
    return [a, b]

def mutation(l : list):
    p = 0.01
    res = []
    for j in range(len(l)):
        a = l[j]
        for i in range(8):
            if random.random() < p:
                a = a ^ (1 << i)
        res.append(a)
    return res

def find_max(l : list):
    index = 0
    maximum = l[0]
    for i in range(len(l)):
        if l[i] > maximum:
            maximum = l[i]
            index = i
    return index

def create_criteria(l : list):
    res = []
    for i in range(len(l)):
        res.append(1 / (1 + math.sqrt(abs(l[i]))))
    return res
    
def genetic_iter():
    """initialization"""
    critearia_value = 0.99
    population = []
    criteria = []
    normalize_criteria = []
    indexes = []
    for i in range(16):
        indexes.append(i)
    for i in range(16):
        population.append(random.randint(0, 255))
        criteria.append(f(population[i]))
    criteria = create_criteria(criteria)
    normalize_criteria = normalize(criteria)
    """algorithm"""
    while (min(normalize_criteria) >= critearia_value):
        new_generation = []
        for i in range(16):
            r = random.random()
            index = find_object(normalize_criteria, r)
            new_generation.append(population[index])
        random.shuffle(indexes)
        for i in range(8):
            i1 = random.randint(0, 7)
            i2 = random.randint(0, 7)
            res = hybridization(new_generation[indexes[2 * i]], new_generation[indexes[2 * i + 1]], min(i1, i2), max(i1, i2))
            new_generation[2 * i] = res[0]
            new_generation[2 * i + 1] = res[1]
        population = mutation(new_generation)
        criteria = []
        for i in range(16):
            criteria.append(round(f(population[i])))
        criteria = create_criteria(criteria)
        normalize_criteria = normalize(criteria)
    return population[find_max(normalize_criteria)]

def genetic():
    points = []
    val = []
    for i in range(5):
        points.append(genetic_iter())
        val.append(f(points[i]))
    return points[find_max(val)]
    
print(genetic())
print(f(genetic()))

