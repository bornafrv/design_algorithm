from itertools import permutations
import time

start = time.time()

def graph (adjacency, s, start): 
    vertex = [] 

    for i in range (n): 
        if (i != s): 
            vertex.append(i) 

    min_path = float('inf') 
    next_permutation = permutations(vertex)

    for i in next_permutation:
        current_pathweight = 0
        k = s 

        for j in i: 
            current_pathweight += adjacency[k][j] 
            k = j 

        current_pathweight += adjacency[k][s] 
        min_path = min(min_path, current_pathweight) 

        end = time.time()
        if (end - start >= 10):
             print(min_path)
             return
        
    print(min_path)

n = int(input())
adjacency = []

for i in range (n):
	adjacency.append([int(x) for x in input("").split()])
     
graph(adjacency, 0, start)