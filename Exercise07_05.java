public class Exercise07_05 {
  public static void main(String[] args) {
    int[] numbers = new int[30]; // numbers array will store distinct values, maximum is 10
    int numberOfDistinctValues = 0; // How many distinct numbers are in the
                                    // array
    java.util.Scanner input = new java.util.Scanner(System.in);
    System.out.print("Enter " + numbers.length + " numbers: ");

    for (int i = 0; i < numbers.length; i++) {
      // Read an input
      int value = input.nextInt();

      // Step 1: Check if value is in numbers
      boolean isInTheArray = false;
      for (int j = 0; j < numberOfDistinctValues; j++) {
      	if (value == numbers[j]) {
          isInTheArray = true;
      	}
      }
      
      // Step 2: If value is not in numbers, add it into numbers
      if (!isInTheArray) {
      	numbers[numberOfDistinctValues] = value;

      	// Step 3: Increment numberOfDistinctValues       
      	numberOfDistinctValues++;
      }
    }

    System.out.println("The number of distinct values is " 
    	+ numberOfDistinctValues);
    for (int i = 0; i < numberOfDistinctValues; i++)
      System.out.print(numbers[i] + " ");
  }
}

