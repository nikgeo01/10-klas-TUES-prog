import java.io.*;

public class Main {
    public static void main(String[] args) {
        BufferedReader reader = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
        try {
            System.out.print("Number of elements: ");
            String line = reader.readLine();
            int N = Integer.parseInt(line.trim());

            System.out.print("Elements: ");
            line = reader.readLine();
            String[] tokens = line.trim().split("\\s+");

            if (tokens.length < N) {
                System.out.println("Invalid number of elements");
                return;
            }

            LinkedList list = new LinkedList();
            Vector vector = new Vector();

            for (int i = 0; i < N; i++) {
                int value = Integer.parseInt(tokens[i]);

                if (list.contains(value) || vector.contains(value)) {
                    continue;
                }

                if (value % 2 != 0) {
                    list.addLast(value);
                } else {
                    vector.pushBack(value);
                }
            }

            System.out.print("Odd: ");
            for (int num : list) {
                System.out.print(num + " ");
            }
            System.out.println();

            System.out.print("Even: ");
            for (int num : vector) {
                System.out.print(num + " ");
            }
            System.out.println();

        } catch (java.io.IOException e) {
            System.out.println(e.getMessage());
        } catch (NumberFormatException e) {
            System.out.println(e.getMessage());
        }
    }
}
