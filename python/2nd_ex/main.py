def err(exc):
    raise Exception(exc)

def init():
    val = int(input())
    if val <= 0:
        err("Invalid input")
    return val

def cmp(arr, v):
    if v < max(arr):
        err("The volume of the watering can is not enough to water the flower")

def counting_steps(arr, v):
    count = 0
    tmp = v

    for i in range(len(arr)):
        if tmp < arr[i]:
            tmp = v
            count += (i) * 2
        count += 1
        tmp -= arr[i]

    return count

n = init()

arr = []
for _ in range(n):
    arr.append(init())

v = init()

cmp(arr, v)

print(counting_steps(arr, v))
