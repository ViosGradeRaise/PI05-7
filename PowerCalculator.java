public class PowerCalculator {

    public static double power(double x, int n) {
        if (n == 0)
            return 1; // x^0 = 1
        else if (n < 0)
            return 1 / power(x, -n); // при отрицательных числах
        else
            return x * power(x, n - 1); // рекурсия
    }

    public static void main(String[] args) {
        double base = 2.0;
        int exponent = 3;
        System.out.println(base + "^" + exponent + " = " + power(base, exponent));
    }
}
