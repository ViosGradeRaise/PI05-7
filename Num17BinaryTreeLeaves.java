class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    
    TreeNode(int val) {
        this.val = val;
    }
}

public class Num17BinaryTreeLeaves {
    
    // Рекурсивный метод подсчета листьев
    public int countLeaves(TreeNode root) {
        // Базовый случай: пустое дерево
        if (root == null) {
            return 0;
        }
        
        // Если узел является листом (нет детей)
        if (root.left == null && root.right == null) {
            return 1;
        }
        
        // Рекурсивно считаем листья в левом и правом поддереве
        return countLeaves(root.left) + countLeaves(root.right);
    }
    
    public static void main(String[] args) {
        // Создаем дерево:
        //       1
        //      / \
        //     2   3
        //    / \
        //   4   5
        
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        
        Num17BinaryTreeLeaves tree = new Num17BinaryTreeLeaves();
        
        System.out.println("Количество листьев : " + 
                          tree.countLeaves(root)); // Вывод: 3
    }
}
