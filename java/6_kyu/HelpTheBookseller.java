import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;

/**
A bookseller has lots of books classified in 26 categories labeled A, B, ... Z. Each book has a code c of 3, 4, 5 or more characters. 
The 1st character of a code is a capital letter which defines the book category.
In the bookseller's stocklist each code c is followed by a space and by a positive integer n (int n >= 0) which indicates the quantity of books of this code in stock.

For example an extract of a stocklist could be:
    L = {"ABART 20", "CDXEF 50", "BKWRK 25", "BTSQZ 89", "DRTYM 60"}.
    or
    L = ["ABART 20", "CDXEF 50", "BKWRK 25", "BTSQZ 89", "DRTYM 60"] or ....

You will be given a stocklist (e.g. : L) and a list of categories in capital letters e.g :
    M = {"A", "B", "C", "W"} 
    or
    M = ["A", "B", "C", "W"] or ...

and your task is to find all the books of L with codes belonging to each category of M and to sum their quantity according to each category.
For the lists L and M of example you have to return the string (in Haskell/Clojure/Racket a list of pairs):

    (A : 20) - (B : 114) - (C : 50) - (W : 0)

where A, B, C, W are the categories, 20 is the sum of the unique book of category A, 
114 the sum corresponding to "BKWRK" and "BTSQZ", 50 corresponding to "CDXEF" and 0 to category 'W' since there are no code beginning with W.
If L or M are empty return string is "" (Clojure and Racket should return an empty array/list instead).

Note:
    In the result codes and their values are in the same order as in M.
*/

public class HelpTheBookseller
{

	public static String stockSummary(String[] lstOfArt, String[] lstOf1stLetter) {

        if( lstOfArt.length == 0 || lstOf1stLetter.length == 0){
            return "";
        }

        BookStoreDB bookStoreDB = new BookStoreDB();
        final String delimiter = " - ";
        
        for (String string : lstOfArt) {
            bookStoreDB.putValues(string);
        }

        String result = "";
        for (String c : lstOf1stLetter) {
            String encoded = encode(c.charAt(0), bookStoreDB.getValues(c.charAt(0)));
            result += encoded + delimiter;
        }

		return result.substring(0, result.length()-delimiter.length());
    }
    
    private static String encode(Character c, int value)
    {
        return "(" + c + " : " + value + ")" ;
    }
    
    private static class BookStoreDB
    {
        private Map<Character, Integer> db = new HashMap<Character, Integer>();

        public void putValues(String encoded)
        {
            String[] splited = encoded.split("\\s+");
            Integer value = Integer.parseInt(splited[1]);

            Character c = splited[0].charAt(0);
            if(db.containsKey(c)){
                value += db.get(c);
            }
            db.put(c, value);                
        }

        public int getValues(Character c)
        {
            if(db.containsKey(c)){
                return db.get(c);
            }
            return 0;
        }
    };

    public static void main(String[] args) {
        HelpTheBookseller tester = new HelpTheBookseller();
        tester.testAll();
    }

    private void testAll(){
        test(new String[]{"ABART 20", "CDXEF 50", "BKWRK 25", "BTSQZ 89", "DRTYM 60"}, new String[]{"A", "B", "C", "W"}, "(A : 20) - (B : 114) - (C : 50) - (W : 0)" );
        test(new String[]{"ABAR 200", "CDXE 500", "BKWR 250", "BTSQ 890", "DRTY 600"}, new String[]{"A", "B"}, "(A : 200) - (B : 1140)" );
    }

    private void test(String[] lstOfArt, String[] lstOf1stLetter, String expected){
        String result = stockSummary(lstOfArt, lstOf1stLetter);
        if(result.equals(expected)){
            System.out.println("Success!");
        } 
        else{
            System.out.println("Failure!");
            System.out.println("\tExpected: " + expected);
            System.out.println("\tActual:   " + result);
        }
    }
}