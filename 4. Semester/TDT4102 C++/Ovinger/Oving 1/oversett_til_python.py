############## [1] Kodeforståelse: oversett til Python 10%) ##############

def isFibonacciNumber(n): 
    a = 0
    b = 1
    while (b < n):
        temp = b
        b += a
        a = temp
    return b == n

n = int(144)
print(isFibonacciNumber(n))

# Komentar: Programmet oversatt til python, men verken c++
# eller dette programmet gjenkjenner 0 som et fiboaccinummer.
