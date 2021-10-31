import java.lang.Math.*;
import java.util.Scanner;
class Main {
  
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while (sc.hasNextLong()) {
      long num1 = sc.nextLong(), num2 = sc.nextLong(); 
      long difference = Math.abs(num1 - num2);
      System.out.println(difference);
    }
    System.exit(0);

  }
}
