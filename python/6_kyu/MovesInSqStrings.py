    # You are given a string of n lines, each substring being n characters long: For example:
    #     s = "abcd\nefgh\nijkl\nmnop"
    # We will study some transformations of this square of strings.
    #     Clock rotation 180 degrees: rot
    #         rot(s) => "ponm\nlkji\nhgfe\ndcba"
    #     selfie_and_rot(s) (or selfieAndRot or selfie-and-rot) It is initial string + string obtained by clock rotation 180 degrees with dots interspersed in order (hopefully) to better show the rotation when printed.
    #         s = "abcd\nefgh\nijkl\nmnop" --> "abcd....\nefgh....\nijkl....\nmnop....\n....ponm\n....lkji\n....hgfe\n....dcba"
    # Task:
    #     Write these two functions rotand selfie_and_rot
    #     and high-order function oper(fct, s) where
    #     fct is the function of one variable f to apply to the string s (fct will be one of rot, selfie_and_rot)


def rot(strng):
    return strng[::-1]
def selfie_and_rot(strng):
    delimiter = "\n"
    result = delimiter.join( x+"."*len(x) for x in strng.split(delimiter) ) 
    return result + delimiter + rot(result)
def oper(fct, s):
    return fct(s)

print(oper(selfie_and_rot,"abcd\nefgh\nijkl\nmnop") )