import math

testes = int(input())

for i in range(testes):
    C = int(input())
    L = int((-1 + math.sqrt(1 + 24*C))/6)
    print(L)