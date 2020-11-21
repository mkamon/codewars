import java.util.HashMap;

/**
 * 
 * @brief 
 *  Deoxyribonucleic acid (DNA) is a chemical found in the nucleus of cells and carries the "instructions" for the development and functioning of living organisms.
 *  If you want to know more http://en.wikipedia.org/wiki/DNA
 *  In DNA strings, symbols "A" and "T" are complements of each other, as "C" and "G". You have function with one side of the DNA (string, except for Haskell); 
 *  you need to get the other complementary side. DNA strand is never empty or there is no DNA at all (again, except for Haskell).
 *  More similar exercise are found here http://rosalind.info/problems/list-view/ (source)
 *  DnaStrand.makeComplement("ATTGC") // return "TAACG"
 *  DnaStrand.makeComplement("GTAT") // return "CATA"
 * 
 * 
 * 
 * 
 */

public class ComplementaryDNA {

    private static final HashMap<Character, Character> complemets;
    static {
        complemets = new HashMap<Character, Character>();
        complemets.put('A','T');
        complemets.put('T','A');
        complemets.put('C','G');
        complemets.put('G','C');

    }

    public static String makeComplement(String dna) {
    
        String result = "";
        for(int i=0; i<dna.length(); i++){
            result += complemets.get(dna.charAt(i));
        }

        return result;
    }
};