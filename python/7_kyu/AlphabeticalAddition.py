# Your task is to add up letters to one letter.

# The function will be given a variable amount of arguments, each one being a letter to add.
# Notes:

#     Letters will always be lowercase.
#     Letters can overflow (see second to last example of the description)
#     If no letters are given, the function should return 'z'

# Examples:

# add_letters('a', 'b', 'c') = 'f'
# add_letters('a', 'b') = 'c'
# add_letters('z') = 'z'
# add_letters('z', 'a') = 'a'
# add_letters('y', 'c', 'b') = 'd' # notice the letters overflowing
# add_letters() = 'z'

def add_letters(*letters):
    alphabet = "zabcdefghijklmnopqrstuvwxy"
    result=sum(alphabet.find(x) for x in letters ) 
    if result < 1 :
        return 'z'
    else :
        return alphabet[result%26]

print(add_letters('a', 'b', 'c'))
print(add_letters('a', 'b') )
print(add_letters('z') )
print(add_letters('y', 'c', 'b'))
print(add_letters())