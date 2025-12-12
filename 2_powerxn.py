def power(x, n):
    if n == 0:
        return 1 # x^0 = 1
    elif n > 0:
        return x * power(x, n - 1) # при отрицательных числах
    else:
        return 1 / power(x, -n) # рекурсия

x = 2
n = 4
print(power(x,n))
