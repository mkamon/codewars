import java.math.*;
/**
 * Your task is to construct a building which will be a pile of n cubes. 
 * The cube at the bottom will have a volume of n^3, the cube above will have volume of (n-1)^3 and so on until the top which will have a volume of 1^3.
 * You are given the total volume m of the building. Being given m can you find the number n of cubes you will have to build?
 * The parameter of the function findNb (find_nb, find-nb, findNb) will be an integer m 
 * and you have to return the integer n such as n^3 + (n-1)^3 + ... + 1^3 = m if such a n exists or -1 if there is no such n.
 */

 


public class BuildPileCubes {
	
	public static long findNb(long m) {
        
        long n = 0;
        long sum = 0;
        
        while( sum < m ){
            n++;
            sum += (long) Math.pow(n,3);
        }

        if(sum == m){
            return n;
        }


        return -1;
    }	
    
    public static void main(String[] args) {
        testAll();
    }

    private static void test(long input, long expected){
        long result = findNb(input);
        if( result == expected ){
            System.out.println("Success!!");
        }
        else {
            System.out.println("Failure!!");
            System.out.println("\tExpected = " + expected);
            System.out.println("\tActuall  = " + result);
        }
    }

    private static void testAll(){
        
        test(4183059834009L, 2022);
        test(24723578342962L, -1);
        test(135440716410000L, 4824);
        test(40539911473216L, 3568);	
    }
}