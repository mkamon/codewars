 
/**
 * Kata Description
 * Trolls are attacking your comment section!
A common way to deal with this situation is to remove all of the vowels from the trolls' comments, neutralizing the threat.
Your task is to write a function that takes a string and return a new string with all vowels removed.
For example, the string "This website is for losers LOL!" would become "Ths wbst s fr lsrs LL!".
Note: for this kata y isn't considered a vowel.
*/


public class DisemvowelTrolls {

    private static String vovels = "[aAeEiIoOuU]";

    /**
     * Remove all vowels from the given input string.
     * @param str The string to remove vowels from.
     * @return A copy of the original string with all vowels removed.
     */
    public static String disemvowel(String str) {
        return str.replaceAll(vovels, "");
    }

    public static void main(String args[])
    {
        doTests();
    }

    private static void doTests()
    {
        test("This website is for losers LOL!", "Ths wbst s fr lsrs LL!");
        test("No offense but,\nYour writing is among the worst I've ever read", "N ffns bt,\nYr wrtng s mng th wrst 'v vr rd");
        test("What are you, a communist?", "Wht r y,  cmmnst?");
    }

    private static void test(String input, String expected)
    {
        String result = disemvowel(input);
        if( !result.equals(expected) ){
            System.out.println("*****Error*****");
            System.out.println("result=" + result );
            System.out.println("expect=" + expected );
        }

    }
}
