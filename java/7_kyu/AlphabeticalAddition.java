/**
Your task is to add up letters to one letter.

The function will be given an array of single character Strings, each one being a letter to add.
Notes:

    Letters will always be lowercase.
    Letters can overflow (see second to last example of the description)
    If no letters are given, the function should return 'z'

Examples:

addLetters("a", "b", "c") = "f"
addLetters("a", "b") = "c"
addLetters("z") = "z"
addLetters("z", "a") = "a"
addLetters("y", "c", "b") = "d" // notice the letters overflowing
addLetters() = "z"
 * 
 */

public class AlphabeticalAddition {

    public static void main(String[] args) {
        System.out.println(addLetters("a","b","c"));
        System.out.println(addLetters("a","b"));
        System.out.println(addLetters("z"));
        System.out.println(addLetters("z", "a"));
        System.out.println(addLetters("y", "c", "b"));
        System.out.println(addLetters());
    }


    public static String addLetters(String... letters) {
        int current = 0;
        for( String c : letters){
            current += (int)c.charAt(0) - 96;
        }
        current = current % 26 + 96;
        if( current == 96 ){
            return "z";
        }

        return  String.valueOf((char)current) ;
    }

}
