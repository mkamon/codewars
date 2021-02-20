import java.util.Arrays;

/**
 * Given two arrays a and b write a function comp(a, b) (or compSame(a, b)) 
 * that checks whether the two arrays have the "same" elements, with the same multiplicities. 
 * "Same" means, here, that the elements in b are the elements in a squared, regardless of the order.
Examples
Valid arrays
    a = [121, 144, 19, 161, 19, 144, 19, 11]  
    b = [121, 14641, 20736, 361, 25921, 361, 20736, 361]
*/
public class AreTheyTheSame {
    
    public static void main(String[] args) {
        testAll();
    }


	public static boolean comp(int[] base, int[] squared) {
        if( base == null || squared == null){
            return false;
        }
        if( base.length != squared.length ){
            return false;
        }
        
        for (int el : base) {
            int el_squared = el * el;
            boolean foundMatch = false;
            for( int i=0; i<squared.length; i++ ){
                if( el_squared == squared[i]){
                    squared[i] = -1;
                    foundMatch=true;
                    break;
                }
            }
            if( !foundMatch ){
                return false;
            }
        }
        return true;
    }

    /// found as higher ranked by best-practice solution on codewars.com 
	public static boolean comp2(int[] base, int[] squared) {
        if( base == null || squared == null){
            return false;
        }
        if( base.length != squared.length ){
            return false;
        }

        int[] base_squared = Arrays.stream(base).map(n -> n*n).toArray();
        Arrays.sort(base_squared);
        Arrays.sort(squared);
        return Arrays.equals(base_squared, squared);
    }


    private static void testAll()
    {
        test(new int[]{121, 144, 19, 161, 19, 144, 19, 11}, new int[]{121, 14641, 20736, 361, 25921, 361, 20736, 361}, true );
        test(new int[]{}, new int[]{}, true );
    }

    private static void test(int[] a, int b[], boolean expected)
    {
        boolean result = comp(a,b);
        if( result == expected ) {
            System.out.println("Success!");
        }
        else {
            System.out.println("Failure! Expected = " + expected + " got = " + result);
        }
    }


}
