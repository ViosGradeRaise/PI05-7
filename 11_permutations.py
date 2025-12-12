from itertools import permutations as itertools_perms

def permutations_builtin(s):
    """Используем встроенную функцию itertools"""
    return [''.join(p) for p in itertools_perms(s)]


print(permutations_builtin("abc"))
