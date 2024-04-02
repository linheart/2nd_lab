def counting_dup(n):
    a = b = int(input())
    count = 0

    for _ in range(n - 1):
        a = int(input())
        if a == b:
            count += 1
        b = a
    return count

print(counting_dup(int(input())))
