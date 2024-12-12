import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        MyBiFunction<Double, Double, Float> add = (a, b) -> (float) (a + b);
        MyBiFunction<Double, Double, Float> subtract = (a, b) -> (float) (a - b);
        MyBiFunction<Double, Double, Float> multiply = (a, b) -> (float) (a * b);
        MyBiFunction<Double, Double, Float> divide = (a, b) -> b != 0 ? (float) (a / b) : null;

        double num1 = 3;
        double num2 = 4;

        System.out.println("Addition: " + add.apply(num1, num2));
        System.out.println("Subtraction: " + subtract.apply(num1, num2));
        System.out.println("Multiplication: " + multiply.apply(num1, num2));
        System.out.println("Division: " + divide.apply(num1, num2));

        MyFunction<List<Integer>, Long> sumList = list -> list.stream().mapToLong(Integer::longValue).sum();
        List<Integer> numbers = Arrays.asList(1, 2, 3, 4, 5);
        System.out.println("Sum of list: " + sumList.apply(numbers));

        MyFunction<Integer, Integer> postIncrement = num -> num + 1;
        MyFunction<Integer, Integer> preIncrement = num -> ++num;

        Integer value = 5;
        System.out.println("Post-increment: " + postIncrement.apply(value));
        System.out.println("Pre-increment: " + preIncrement.apply(value));

        MyBiFunction<String, String, String> concatenate = (base, addition) -> base + addition;

        String baseString = "Hey";
        String addition = " Tedi!";
        System.out.println("Concatenated String: " + concatenate.apply(baseString, addition));
    }
}
