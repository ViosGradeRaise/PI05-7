class TreeNode:
    def __init__(self, value=0, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def count_leaves(root):
    """
    Подсчитывает количество листьев в бинарном дереве (рекурсивно).
    
    Лист - это узел, у которого нет потомков (left и right равны None).
    
    Args:
        root: корень бинарного дерева
    
    Returns:
        int: количество листьев
    """
    # Базовый случай: пустое дерево
    if root is None:
        return 0
    
    # Если узел является листом (нет потомков)
    if root.left is None and root.right is None:
        return 1
    
    # Рекурсивно считаем листья в левом и правом поддеревьях
    return count_leaves(root.left) + count_leaves(root.right)

# Создаём дерево:
#       1
#      / \
#     2   3
#    / \   \
#   4   5   6
#  /
# 7

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)
root.right.right = TreeNode(6)
root.left.left.left = TreeNode(7)

# Листья: 7, 5, 6 (всего 3)

print(f"Кол-во листьев: {count_leaves(root)}")  # 3
