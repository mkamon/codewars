/**

Take an integer n (n >= 0) and a digit d (0 <= d <= 9) as an integer. 
Square all numbers k (0 <= k <= n) between 0 and n. 
Count the numbers of digits d used in the writing of all the k**2. 
Call nb_dig (or nbDig or ...) the function taking n and d as parameters and returning this count.

Examples:

n = 10, d = 1, the k*k are 0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100
We are using the digit 1 in 1, 16, 81, 100. The total count is then 4.

nb_dig(25, 1):
the numbers of interest are
1, 4, 9, 10, 11, 12, 13, 14, 19, 21 which squared are 1, 16, 81, 100, 121, 144, 169, 196, 361, 441
so there are 11 digits `1` for the squares of numbers between 0 and 25.

Note that 121 has twice the digit 1.

*/

public class CountTheDigit {
    public static void main(String[] args) {
        runTests();
    }

    public static int nbDig(int n, int d) {
        int counter = 0;
        for( int i=0; i<=n; i++){
            counter += digitsInSingleNumber(i*i, d);
        }
        return counter;
    }
    
    private static int digitsInSingleNumber(int k, int d )
    {
        int counter = 0;
        do{
            counter += ( k%10 == d ? 1 : 0 );
            k /= 10;
        } while(k>0);
        return counter;
    }


    private static void runTests(){
        test(11, 25, 1);
        test(4700, 5750, 0);
        test(9481, 11011, 2);
        test(7733, 12224, 8);
        test(11905,11549, 1);
    }

    private static void test(int expected, int n, int d){
        int result = nbDig(n, d);
        if( result == expected){
            System.out.println("Success!! result = " + result);
        }
        else{
            System.out.println("Failure!! result = " + result + " expected = " + expected);
        }
    }
}
