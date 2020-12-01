/**
    You are given two arrays a1 and a2 of strings. Each string is composed with letters from a to z. Let x be any string in the first array and y be any string in the second array.
    Find max(abs(length(x) − length(y)))

    If a1 and/or a2 are empty return -1 in each language except in Haskell (F#) where you will return Nothing (None).
    Example:
    a1 = ["hoqq", "bbllkw", "oox", "ejjuyyy", "plmiis", "xxxzgpsssa", "xxwwkktt", "znnnnfqknaz", "qqquuhii", "dvvvwz"]
    a2 = ["cccooommaaqqoxii", "gggqaffhhh", "tttoowwwmmww"]
    mxdiflg(a1, a2) --> 13
 */
import java.lang.*;

public class MaximumLengthDifference {
        
    public static void main(String[] args) {
        testAll();
    }

    public static int mxdiflg(String[] a1, String[] a2) {
        if(a1.length == 0 || a2.length == 0){
            return -1;
        }
        
        int max1min2 = getMaxLength(a1) - getMinLength(a2);
        int max2min1 = getMaxLength(a2) - getMinLength(a1);

        return Math.max(max1min2, max2min1);

    }

    private static int getMaxLength(String[] strArr){
        int max =0; 
        for (String string : strArr) {
            max = Math.max(max, string.length());
        }
        return max;
    }
    private static int getMinLength(String[] strArr){
        int min = Integer.MAX_VALUE;
        for (String string : strArr) {
            min = Math.min(min, string.length());
        }
        return min;
    }


    private static void testAll()
    {
        test(13,
            new String[]{"hoqq", "bbllkw", "oox", "ejjuyyy", "plmiis", "xxxzgpsssa", "xxwwkktt", "znnnnfqknaz", "qqquuhii", "dvvvwz"}, 
            new String[]{"cccooommaaqqoxii", "gggqaffhhh", "tttoowwwmmww"});
    }

    private static void test(int expected, String[] a1, String[] a2){
        int result = mxdiflg(a1, a2);
        if( expected != result){
            System.out.println("Failure: expected=" + expected + " result=" + result );
        }
        else{
            System.out.println("Success!");
        }
    }

}
