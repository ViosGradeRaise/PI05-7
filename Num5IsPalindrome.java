public class Num5IsPalindrome {

    public static boolean isPalindrome(String s) {
        // если длина строки <= 1, строка - палиндром
        if (s.length() <= 1) {
            return true;
        }
        // Сверяем первый и последний символы
        if (s.charAt(0) != s.charAt(s.length() - 1)) {
            return false;
        }
        // рекурсия без первого и последнего символов
        return isPalindrome(s.substring(1, s.length() - 1));
    }

    public static void main(String[] args) {
        String test1 = "racecar";
        String test2 = "hello";

        System.out.println(test1 + " палиндром? " + isPalindrome(test1));
        System.out.println(test2 + " палиндром? " + isPalindrome(test2));
    }
}
