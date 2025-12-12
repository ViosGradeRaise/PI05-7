def is_palindrome(s):
    # Если длина строки <= 1, строка - палиндром
    if len(s) <= 1:
        return True
    # Сверяем первый и последний символ
    if s[0] != s[-1]:
        return False
    # рекурсия строки со 2-го по предпоследний символ
    return is_palindrome(s[1:-1])

print(is_palindrome('rewqwer')) # True
print(is_palindrome('rewqwe')) # False
