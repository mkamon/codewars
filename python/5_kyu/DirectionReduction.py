# Task
# Write a function dirReduc which will take an array of strings and returns an array of strings with the needless directions removed (W<->E or S<->N side by side).
#     The Haskell version takes a list of directions with data Direction = North | East | West | South.
#     The Clojure version returns nil when the path is reduced to nothing.
#     The Rust version takes a slice of enum Direction {NORTH, SOUTH, EAST, WEST}.
# See more examples in "Sample Tests:"
# Notes
#     Not all paths can be made simpler. The path ["NORTH", "WEST", "SOUTH", "EAST"] is not reducible. "NORTH" and "WEST", "WEST" and "SOUTH", "SOUTH" and "EAST" are not directly opposite of each other and can't become such. Hence the result path is itself : ["NORTH", "WEST", "SOUTH", "EAST"].
#     if you want to translate, please ask before translating.

opposite = {'NORTH': 'SOUTH', 'EAST': 'WEST', 'SOUTH': 'NORTH', 'WEST': 'EAST'}

def should_push(stack, next_direction) -> bool:
    if not stack:
        return True
    return not (next_direction == opposite[stack[-1]])

def dirReduc(arr):
    reduced = []
    for dir in arr:
        reduced.append(dir) if should_push(reduced, dir) else reduced.pop(-1)            
    return reduced
