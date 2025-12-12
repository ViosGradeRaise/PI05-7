public class Num8SumArray {

    public static int sumArray(int[] arr, int index) {
        // если длина списка = 0
        if (index >= arr.length) {
            return 0;
        }
        // рекурсия
        return arr[index] + sumArray(arr, index + 1);
    }

    public static void main(String[] args) {
        int[] numbers = {1, 2, 3, 4, 5}; // 15
        int totalSum = sumArray(numbers, 0);
        System.out.println("Сумма элементов: " + totalSum);
    }
}
