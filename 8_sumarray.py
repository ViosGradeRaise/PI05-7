def sum_array(arr):
    # Если длина = 0, вернуть 0
    if not arr:
        return 0
    # рекурсия - значение первого элемента + значения из списка без первого элемента
    return arr[0] + sum_array(arr[1:])
    
arr = [1,2,34,5,4,33,2,0]
print(sum_array(arr)) # 81
