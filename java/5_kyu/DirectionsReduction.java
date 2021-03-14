import java.security.KeyStore.Entry;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.EnumMap;
import java.util.EnumSet;
import java.util.List;
import java.util.Map;
import java.util.Stack;
import java.util.function.Function;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/*
Task

Write a function dirReduc which will take an array of strings and returns an array of strings with the needless directions removed (W<->E or S<->N side by side).

    The Haskell version takes a list of directions with data Direction = North | East | West | South.
    The Clojure version returns nil when the path is reduced to nothing.
    The Rust version takes a slice of enum Direction {NORTH, SOUTH, EAST, WEST}.

See more examples in "Sample Tests:"
Notes

    Not all paths can be made simpler. The path ["NORTH", "WEST", "SOUTH", "EAST"] is not reducible. "NORTH" and "WEST", "WEST" and "SOUTH", "SOUTH" and "EAST" are not directly opposite of each other and can't become such. Hence the result path is itself : ["NORTH", "WEST", "SOUTH", "EAST"].
    if you want to translate, please ask before translating.
*/





public class DirectionsReduction {
    
    public static void main(String[] args) {
        String[] input1 = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
        String[] expectedOutput1 = {"WEST"};
        test(input1, expectedOutput1);


        String[] input2 = {"NORTH", "SOUTH", "SOUTH",  "SOUTH", "SOUTH", "WEST", "NORTH", "WEST"};
        String[] expectedOutput2 = {"SOUTH", "SOUTH", "WEST", "WEST"};
        test(input2, expectedOutput2);

        String[] input3 = {"WEST"};
        String[] expectedOutput3 = {"WEST"};
        test(input3, expectedOutput3);

        String[] input4 = {"SOUTH"};
        String[] expectedOutput4 = {"SOUTH"};
        test(input4, expectedOutput4);


        String[] input5 = {};
        String[] expectedOutput5 = {};
        test(input5, expectedOutput5);
    }

    public static void test(String[] input, String[] expectedOutput){
        String[] reduced =  dirReduc(input);
        boolean result = Arrays.equals(expectedOutput, reduced);
        if(result){
            System.out.println("Success!");
        } 
        else {
            System.out.print("Expected: ");
            for( String str: expectedOutput){
                System.out.print(str + ", ");                
            }
            System.out.print("\nAcctual: ");
            for( String str: reduced){
                System.out.print(str + ", ");                
            }
            System.out.println();
        }
    }


    private enum Direction{
        NORTH("NORTH"), SOUTH("SOUTH"), EAST("EAST"), WEST("WEST");

        private final String name;
        Direction(String name ) { this.name = name;}

        public String getName(){ return name;}

    } 
    
    public static String[] dirReduc(String[] arr) {
        EnumMap<Direction, Long> directionCounter = Stream.of(arr)
            .collect(Collectors.toMap(
                Direction::valueOf,
                x->1L,
                Long::sum,
                ()->{
                    EnumMap<Direction, Long> em = new EnumMap<>(Direction.class);
                    EnumSet.allOf(Direction.class).forEach(c->em.put(c,0L));
                    return em;
                }));

        int northSoutDiff = (int)(directionCounter.get(Direction.NORTH) - directionCounter.get(Direction.SOUTH));
        int westEastDiff = (int)(directionCounter.get(Direction.WEST) - directionCounter.get(Direction.EAST));
        

        List<String> result = new ArrayList<>();
        result.addAll(Collections.nCopies(Math.abs(northSoutDiff),  northSoutDiff > 0 ? Direction.NORTH.name : Direction.SOUTH.name ));
        result.addAll(Collections.nCopies(Math.abs(westEastDiff),  westEastDiff  > 0 ? Direction.WEST.name : Direction.EAST.name ));
        
        return result.toArray(new String[0]);
    }

    public static String[] dirReduc2(String[] arr){
        Stack<String> reduced = new Stack<>();
        for (String direction : arr) {
            if(reduced.empty() || !isReducible(Direction.valueOf(direction), Direction.valueOf(reduced.peek())) ){
                reduced.push(direction);                
            }
            else{                
                reduced.pop();
            }
        }
        return reduced.toArray(String[]::new);
    }

    public static boolean isReducible(Direction dir1, Direction dir2){
        return dir1.equals(Direction.NORTH) && dir2.equals(Direction.SOUTH) ||
                dir1.equals(Direction.SOUTH) && dir2.equals(Direction.NORTH) ||
                dir1.equals(Direction.WEST) && dir2.equals(Direction.EAST) ||
                dir1.equals(Direction.EAST) && dir2.equals(Direction.WEST);
    }

}
