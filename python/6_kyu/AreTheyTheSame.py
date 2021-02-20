# Given two arrays a and b write a function comp(a, b) (orcompSame(a, b)) that checks whether the two arrays have the "same" elements, with the same multiplicities. "Same" means, here, that the elements in b are the elements in a squared, regardless of the order.
# Examples
# Valid arrays
#     a = [121, 144, 19, 161, 19, 144, 19, 11]  
#     b = [121, 14641, 20736, 361, 25921, 361, 20736, 361]


def comp(array1, array2):
    if(array1 is None or array2 is None ):
        return False
    return [x*x for x in sorted(array1)] == sorted(array2)
	