/**
John has invited some friends. His list is:
    s = "Fred:Corwill;Wilfred:Corwill;Barney:Tornbull;Betty:Tornbull;Bjon:Tornbull;Raphael:Corwill;Alfred:Corwill";
Could you make a program that
    makes this string uppercase
    gives it sorted in alphabetical order by last name.
When the last names are the same, sort them by first name. Last name and first name of a guest come in the result between parentheses separated by a comma.
So the result of function meeting(s) will be:
    "(CORWILL, ALFRED)(CORWILL, FRED)(CORWILL, RAPHAEL)(CORWILL, WILFRED)(TORNBULL, BARNEY)(TORNBULL, BETTY)(TORNBULL, BJON)"
It can happen that in two distinct families with the same family name two people have the same first name too.
Notes
    You can see another examples in the "Sample tests".
*/

import java.util.Collections;
import java.util.ArrayList;
import java.util.List;

class Meeting {
    
    public static String meeting(String s) {
        String[] guests = s.toUpperCase().split(";");
        List<String> guestList = new ArrayList<>();

        for (String guest : guests) {
            guestList.add(encode(guest));
        }
        Collections.sort(guestList);

        return String.join("", guestList);
    }

    private static String encode(String guest){
        String[] name = guest.split(":");
        return "(" + name[1] + ", " + name[0] + ")";
    }


    public static void main(String[] args) {
        testAll();
    }

    private static void testAll()
    {
        test("Alexis:Wahl;John:Bell;Victoria:Schwarz;Abba:Dorny;Grace:Meta;Ann:Arno;Madison:STAN;Alex:Cornwell;Lewis:Kern;Megan:Stan;Alex:Korn", 
            "(ARNO, ANN)(BELL, JOHN)(CORNWELL, ALEX)(DORNY, ABBA)(KERN, LEWIS)(KORN, ALEX)(META, GRACE)(SCHWARZ, VICTORIA)(STAN, MADISON)(STAN, MEGAN)(WAHL, ALEXIS)");
        test("John:Gates;Michael:Wahl;Megan:Bell;Paul:Dorries;James:Dorny;Lewis:Steve;Alex:Meta;Elizabeth:Russel;Anna:Korn;Ann:Kern;Amber:Cornwell", 
            "(BELL, MEGAN)(CORNWELL, AMBER)(DORNY, JAMES)(DORRIES, PAUL)(GATES, JOHN)(KERN, ANN)(KORN, ANNA)(META, ALEX)(RUSSEL, ELIZABETH)(STEVE, LEWIS)(WAHL, MICHAEL)");
        test("Alex:Arno;Alissa:Cornwell;Sarah:Bell;Andrew:Dorries;Ann:Kern;Haley:Arno;Paul:Dorny;Madison:Kern", 
            "(ARNO, ALEX)(ARNO, HALEY)(BELL, SARAH)(CORNWELL, ALISSA)(DORNY, PAUL)(DORRIES, ANDREW)(KERN, ANN)(KERN, MADISON)");
    }

    private static void test(String input, String expected)
    {
        String result = meeting(input);
        if(result.equals(expected)){
            System.out.println("Success!");
        }
        else {
            System.out.println("FAILURE!");
            System.out.println("\tExcpected = " + expected);
            System.out.println("\tActual    = " + result);
        }
    }

}


// Other solution that is nicer:
// import java.util.Arrays;
// import java.util.stream.Collectors;

// class Meeting {
    
//     public static String meeting(String s) {
//       return Arrays.stream(s.toUpperCase().split(";"))
//                    .map(guest -> guest.replaceAll("(\\w+):(\\w+)", "($2, $1)"))
//                    .sorted()
//                    .collect(Collectors.joining(""));
//     }
// }