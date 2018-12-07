import numpy as np 
from itertools import combinations 
import copy
from math import pi
func = lambda x, y: (x**2.-4.*x+3.)/256
class GeneticEvolution:
    def __init__(self, func, mut_prob=0.1, kill_portion=0.2, max_pairs=1000):
        self.func = func
        self.population = [] 
        # Current symbolic expression
        self.mutation_probability = mut_prob
        self.portion = kill_portion
        self.max_pairs = max_pairs
    def generate_random_population(self, size=500):
        self.population = np.random.rand(100, 2).tolist()
    def initialize(self):
        self.generate_random_population()
    def evolute(self, n_steps=1000):
        n = 0
        while n < n_steps:
            #print('????:', n)
            n += 1
            ind = 0
            newpopulation = copy.copy(self.population) 
            for comb in combinations(range(len(self.population)), 2):
                ind += 1
                if ind > self.max_pairs:
                    break
                a = self.mutate(self.population[comb[0]])
                b = self.mutate(self.population[comb[1]])
                newitem = self.crossover(a, b)
                newpopulation.append(newitem)
            self.population = self.killing(newpopulation) 
        print(self.population)
        return np.min([func(x,y) for x, y in self.population])
    def killing(self, population):
        res = np.argsort([self.func(*item) for item in population])
        res = res[:np.random.poisson(int(len(population) * self.portion))]
        return np.array(population)[res].tolist()
    def crossover(self, a, b, prob=0.5):
        if np.random.rand() >  prob:
            return [a[0], b[1]]
        else:
            return [b[0], a[1]]
    def mutate(self, a):
        if np.random.rand() < self.mutation_probability:
            newa = a + (np.random.rand(2) -0.5)*0.05
        else:
            newa = a
        return newa
g = GeneticEvolution(func=func)
g.initialize()
res = g.evolute()
print('opt rez:', res)
