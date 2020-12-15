/**
    You are given a string of n lines, each substring being n characters long: For example:
        s = "abcd\nefgh\nijkl\nmnop"
    We will study some transformations of this square of strings.
        Clock rotation 180 degrees: rot
            rot(s) => "ponm\nlkji\nhgfe\ndcba"
        selfie_and_rot(s) (or selfieAndRot or selfie-and-rot) It is initial string + string obtained by clock rotation 180 degrees with dots interspersed in order (hopefully) to better show the rotation when printed.
            s = "abcd\nefgh\nijkl\nmnop" --> "abcd....\nefgh....\nijkl....\nmnop....\n....ponm\n....lkji\n....hgfe\n....dcba"
    Task:
        Write these two functions rotand selfie_and_rot
        and high-order function oper(fct, s) where
        fct is the function of one variable f to apply to the string s (fct will be one of rot, selfie_and_rot)

 */



import java.util.function.*;
import java.lang.*;

public class MovesInSqStrings
{
    private static final String delimiter = "\n";
    public static void main(String[] args) {
        testAll();
    }

    public static String rot(String strng) {
        StringBuffer buffer = new StringBuffer(strng);
        return buffer.reverse().toString();
    }
    public static String selfieAndRot(String strng) {
        String[] lines = strng.split(delimiter);
        for( int i=0; i<lines.length; i++){
            lines[i] += ".".repeat(lines[i].length());
        }
        String result = String.join(delimiter, lines);
        result += delimiter + rot(result);
        return result;
    }
    public static String oper(Function<String,String> operation, String s) {
        return operation.apply(s);
    }

    private static void test(String result, String expected) {
        if( result.equals(expected) ){
            System.out.println("Success!");
        }
        else {
            System.out.println("Failure!");
            System.out.println("\tExpected:");
            System.out.println(expected);
            System.out.println("\tActuall:");
            System.out.println(result);
        }
    }


    private static void testAll(){
        System.out.println("Fixed Tests rot");
        test(MovesInSqStrings.oper(MovesInSqStrings::rot, "fijuoo\nCqYVct\nDrPmMJ\nerfpBA\nkWjFUG\nCVUfyL"), 
                "LyfUVC\nGUFjWk\nABpfre\nJMmPrD\ntcVYqC\nooujif");
        test(MovesInSqStrings.oper(MovesInSqStrings::rot, "rkKv\ncofM\nzXkh\nflCB"), 
        "BClf\nhkXz\nMfoc\nvKkr");
        
        System.out.println("Fixed Tests selfieAndRot");
        test(MovesInSqStrings.oper(MovesInSqStrings::selfieAndRot, "xZBV\njsbS\nJcpN\nfVnP"), 
                "xZBV....\njsbS....\nJcpN....\nfVnP....\n....PnVf\n....NpcJ\n....Sbsj\n....VBZx");
        test(MovesInSqStrings.oper(MovesInSqStrings::selfieAndRot, "uLcq\nJkuL\nYirX\nnwMB"),
                "uLcq....\nJkuL....\nYirX....\nnwMB....\n....BMwn\n....XriY\n....LukJ\n....qcLu");

    }
}