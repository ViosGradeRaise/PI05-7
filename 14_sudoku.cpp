#include <iostream>
#include <vector>

using namespace std;

const int N = 9;

class SudokuSolver {
public:
    /**
     * Решает судоку методом backtracking
     * @param board - двумерный вектор 9x9, где 0 означает пустую клетку
     * @return true если решение найдено, false если решения нет
     */
    bool solveSudoku(vector<vector<int>>& board) {
        int row, col;
        
        // Находим пустую клетку
        if (!findEmpty(board, row, col)) {
            return true; // Все клетки заполнены - судоку решено
        }
        
        // Пробуем числа от 1 до 9
        for (int num = 1; num <= 9; num++) {
            if (isValid(board, num, row, col)) {
                // Размещаем число
                board[row][col] = num;
                
                // Рекурсивно пытаемся решить дальше
                if (solveSudoku(board)) {
                    return true;
                }
                
                // Если не получилось - откатываем (backtrack)
                board[row][col] = 0;
            }
        }
        
        return false; // Решение не найдено
    }
    
    /**
     * Выводит доску судоку в консоль
     */
    void printBoard(const vector<vector<int>>& board) {
        for (int i = 0; i < N; i++) {
            if (i % 3 == 0 && i != 0) {
                cout << "- - - - - - - - - - - -" << endl;
            }
            
            for (int j = 0; j < N; j++) {
                if (j % 3 == 0 && j != 0) {
                    cout << " | ";
                }
                
                cout << board[i][j];
                
                if (j != N - 1) {
                    cout << " ";
                } else {
                    cout << endl;
                }
            }
        }
    }

private:
    /**
     * Находит пустую клетку (со значением 0)
     * @param board - игровое поле
     * @param row - ссылка для сохранения номера строки
     * @param col - ссылка для сохранения номера столбца
     * @return true если пустая клетка найдена, false если нет
     */
    bool findEmpty(const vector<vector<int>>& board, int& row, int& col) {
        for (row = 0; row < N; row++) {
            for (col = 0; col < N; col++) {
                if (board[row][col] == 0) {
                    return true;
                }
            }
        }
        return false;
    }
    
    /**
     * Проверяет, можно ли разместить число num в позиции (row, col)
     * @param board - игровое поле
     * @param num - число для проверки (1-9)
     * @param row - номер строки
     * @param col - номер столбца
     * @return true если размещение допустимо, false иначе
     */
    bool isValid(const vector<vector<int>>& board, int num, int row, int col) {
        // Проверка строки
        for (int j = 0; j < N; j++) {
            if (board[row][j] == num && j != col) {
                return false;
            }
        }
        
        // Проверка столбца
        for (int i = 0; i < N; i++) {
            if (board[i][col] == num && i != row) {
                return false;
            }
        }
        
        // Проверка квадрата 3x3
        int boxRow = (row / 3) * 3;
        int boxCol = (col / 3) * 3;
        
        for (int i = boxRow; i < boxRow + 3; i++) {
            for (int j = boxCol; j < boxCol + 3; j++) {
                if (board[i][j] == num && (i != row || j != col)) {
                    return false;
                }
            }
        }
        
        return true;
    }
};

int main() {
    // Пример судоку (0 означает пустую клетку)
    vector<vector<int>> board = {
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
    
    SudokuSolver solver;
    
    cout << "Исходное судоку:" << endl;
    solver.printBoard(board);
    cout << endl;
    
    if (solver.solveSudoku(board)) {
        cout << "Решение найдено:" << endl;
        solver.printBoard(board);
    } else {
        cout << "Решение не существует" << endl;
    }
    
    return 0;
}
