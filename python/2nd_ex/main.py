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




n = int(input())
arr = list(map(int, input().split()))

if len(arr) != n:
    raise Exception("The array does not consist of n elements")

v = int(input())

if v < max(arr):
    raise Exception("The volume of the watering can is not enough to water the flower")

print(counting_steps(arr, v))
