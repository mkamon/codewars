/**
The examples below show you how to write function accum:
Examples:
accum("abcd") -> "A-Bb-Ccc-Dddd"
accum("RqaEzty") -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
accum("cwAt") -> "C-Ww-Aaa-Tttt"
The parameter of accum is a string which includes only letters from a..z and A..Z. 
*/

public class Mumbling {
    
    public static String accum(String s) {
            String result="";
            for(int i=0; i<s.length(); i++){
                String temp = "";
                temp += s.charAt(i);
                result += temp.toUpperCase() + temp.toLowerCase().repeat(i) + '-';
            }
            return result.substring(0, result.length() - 1);
       }


       public static void main(String args[] ){
        System.out.println(accum("DUPA"));

       }
}
