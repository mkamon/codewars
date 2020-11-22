#  The examples below show you how to write function accum:
# Examples:
# accum("abcd") -> "A-Bb-Ccc-Dddd"
# accum("RqaEzty") -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
# accum("cwAt") -> "C-Ww-Aaa-Tttt"
# The parameter of accum is a string which includes only letters from a..z and A..Z.

def accumChar(c, n):
    return c.upper() + c.lower()*n

def accum(s):
    index=0
    arr=[]
    for x in s :
        arr.append(accumChar(x,index))
        index=index+1

    return '-'.join(arr)

def accum2(s) :
    return '-'.join( [x.upper()+x.lower()*i for i,x in enumerate(s)])

print(accum("SOme Text"))
print(accum2("SOme Text"))