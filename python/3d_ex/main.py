def counting_dup(arr):
    count = 0
    for i in range(1, len(arr)):
        if arr[i] == arr[i - 1]:
            count += 1
    return count

arr = [int(i) for i in input("Input number array: ").split(' ') if  i.strip()]

if not arr:
    raise Exception("Empty array")

print(counting_dup(arr))
