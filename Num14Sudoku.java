public class Num14Sudoku {
    private static final int SIZE = 9;
    private static final int EMPTY = 0;
    
    /**
     * Решает судоку с помощью алгоритма backtracking
     * @param board двумерный массив 9x9 с судоку (0 - пустая клетка)
     * @return true если решение найдено, false если решения нет
     */
    public static boolean solveSudoku(int[][] board) {
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                // Ищем пустую клетку
                if (board[row][col] == EMPTY) {
                    // Пробуем цифры от 1 до 9
                    for (int num = 1; num <= SIZE; num++) {
                        if (isValid(board, row, col, num)) {
                            // Помещаем число
                            board[row][col] = num;
                            
                            // Рекурсивно решаем дальше
                            if (solveSudoku(board)) {
                                return true;
                            }
                            
                            // Откатываем изменения (backtrack)
                            board[row][col] = EMPTY;
                        }
                    }
                    // Если ни одно число не подошло
                    return false;
                }
            }
        }
        // Все клетки заполнены
        return true;
    }
    
    /**
     * Проверяет, можно ли поместить число в данную клетку
     */
    private static boolean isValid(int[][] board, int row, int col, int num) {
        // Проверка строки
        for (int c = 0; c < SIZE; c++) {
            if (board[row][c] == num) {
                return false;
            }
        }
        
        // Проверка столбца
        for (int r = 0; r < SIZE; r++) {
            if (board[r][col] == num) {
                return false;
            }
        }
        
        // Проверка квадрата 3x3
        int boxRow = row - row % 3;
        int boxCol = col - col % 3;
        for (int r = boxRow; r < boxRow + 3; r++) {
            for (int c = boxCol; c < boxCol + 3; c++) {
                if (board[r][c] == num) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    /**
     * Выводит судоку в консоль
     */
    public static void printBoard(int[][] board) {
        for (int row = 0; row < SIZE; row++) {
            if (row % 3 == 0 && row != 0) {
                System.out.println("------+-------+------");
            }
            for (int col = 0; col < SIZE; col++) {
                if (col % 3 == 0 && col != 0) {
                    System.out.print("| ");
                }
                System.out.print(board[row][col] + " ");
            }
            System.out.println();
        }
    }
    
    /**
     * Пример использования
     */
    public static void main(String[] args) {
        int[][] board = {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
        };
        
        System.out.println("Исходное судоку:");
        printBoard(board);
        
        if (solveSudoku(board)) {
            System.out.println("\nРешение:");
            printBoard(board);
        } else {
            System.out.println("\nРешение не найдено!");
        }
    }
}
