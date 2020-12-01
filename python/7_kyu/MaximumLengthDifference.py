# You are given two arrays a1 and a2 of strings. Each string is composed with letters from a to z. Let x be any string in the first array and y be any string in the second array.

# Find max(abs(length(x) − length(y)))

# If a1 and/or a2 are empty return -1 in each language except in Haskell (F#) where you will return Nothing (None).
# Example:

# a1 = ["hoqq", "bbllkw", "oox", "ejjuyyy", "plmiis", "xxxzgpsssa", "xxwwkktt", "znnnnfqknaz", "qqquuhii", "dvvvwz"]
# a2 = ["cccooommaaqqoxii", "gggqaffhhh", "tttoowwwmmww"]
# mxdiflg(a1, a2) --> 13

def mxdiflg(a1, a2):
    if len(a1) == 0 or len(a2) == 0:
        return -1
    max1 = len(max(a1, key=len))
    min1 = len(min(a1, key=len))
    max2 = len(max(a2, key=len))
    min2 = len(min(a2, key=len))
    return max(max1-min2, max2-min1)

def mxdiflg2(a1, a2):
    if len(a1) == 0 or len(a2) == 0:
        return -1
    return max( [abs(len(x) - len(y)) for x in a1 for y in a2 ])


a1 = ["hoqq", "bbllkw", "oox", "ejjuyyy", "plmiis", "xxxzgpsssa", "xxwwkktt", "znnnnfqknaz", "qqquuhii", "dvvvwz"]
a2 = ["cccooommaaqqoxii", "gggqaffhhh", "tttoowwwmmww"]
print(mxdiflg(a1, a2))
print(mxdiflg2(a1, a2))