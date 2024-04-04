import math

def err(exc):
    raise Exception(exc)

def init():
    val = int(input())
    if val <= 0:
        err("Invalid input")
    return val

def func(S, N, M):
    if S * M > (S - S // 7) * N:
        return -1
    return math.ceil(S * M / N)

S = init()
N = init()
M = init()

print(func(S, N, M))
