def err(exc):
    raise Exception(exc)

def init():
    return int(input())

def counting_dup(n):
    a = b = init()
    count = 0

    for _ in range(n - 1):
        a = init()
        if a == b:
            count += 1
        b = a
    return count

n = init()
if n <= 0:
    err("Invalid input")

print(counting_dup(n))
