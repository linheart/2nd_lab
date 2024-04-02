S = int(input("Input the number of days: "))
N = int(input("Input the maximum number of units of food per day that a traveler can buy at the store: "))
M = int(input("Input the number of units of food per day that the traveler needs to survive: "))

def func(S, M, N):
    if S * M > (S - S // 7) * N:
        return -1

    food = N
    days = 1

    while food <= S * M:
        food += N
        days += 1

    return days - 1

print(func(S, M, N))
