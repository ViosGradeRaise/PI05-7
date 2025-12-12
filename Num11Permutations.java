import java.util.*;

public class Num11Permutations {
    
    public static List<String> permutations(String s) {
        List<String> result = new ArrayList<>();
        
        // если строка из 0 или 1 символа
        if (s.length() <= 1) {
            result.add(s);
            return result;
        }
        
        // Для каждого символа в строке
        for (int i = 0; i < s.length(); i++) {
            // Выбираем текущий символ
            char current = s.charAt(i);
            
            // Получаем оставшиеся символы
            String remaining = s.substring(0, i) + s.substring(i + 1);
            
            // Рекурсивно генерируем перестановки оставшихся символов
            List<String> perms = permutations(remaining);
            
            // Добавляем текущий символ к каждой перестановке
            for (String perm : perms) {
                result.add(current + perm);
            }
        }
        
        return result;
    }
    
    public static void main(String[] args) {
        System.out.println(permutations("abc"));
        // [abc, acb, bac, bca, cab, cba]
        
        System.out.println(permutations("ab"));
        // [ab, ba]
        
        System.out.println(permutations("a"));
        // [a]
    }
}
