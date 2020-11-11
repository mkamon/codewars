
/// Kata Description
/*
All we eat is water and dry matter.
John bought potatoes: their weight is 100 kilograms. Potatoes contain water and dry matter.
The water content is 99 percent of the total weight. He thinks they are too wet and puts them in an oven - at low temperature - for them to lose some water.
At the output the water content is only 98%.
What is the total weight in kilograms (water content plus dry matter) coming out of the oven?
He finds 50 kilograms and he thinks he made a mistake: "So much weight lost for such a small change in water content!"
Can you help him?

Write function potatoes with
    @param[in] int parameter p0 - initial percent of water-
    @param[in] int parameter w0 - initial weight -
    @param[in] int parameter p1 - final percent of water -
    @return the final weight coming out of the oven w1 truncated as an int.
Example:
potatoes(99, 100, 98) --> 50
*/


public class DryingPotatos
{
    public static int potatoes(int p0, int w0, int p1) {        
        double finalMass = (double)w0 * ((double)(100-p0) / (100-p1)) ;
        return (int)finalMass ;
    }

    public static void main(String[] args)
    {
        test();
    }

    private static void dotest(int p0, int w0, int p1, int expected) {
        int result = DryingPotatos.potatoes(p0, w0, p1);
        if (expected != result)
            System.out.println("Expected = " + expected + " result = " + result);
    }    
    
    public static void test() {
        dotest(82, 127, 80, 114);
        dotest(93, 129, 91, 100);
    }
}