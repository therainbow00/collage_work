#sub = 100
def test(num1, num2):    #function signature

    #this is a test function which adds, multiply and subtract conditionally
    #inputs are two numbers (integers, float)
    #the output is a string(msg).

    #print(num1, num2, num1 + num2)    #displays

    if num1 >= num2 or num2 < 0:    #conditional, jump inside this block if num1 > num2 == true
        sum = num1 + num2
        print(sum)

    elif 3 <= num1 < 6:
        mul = num1 * num2
        print(mul)

    else:    #either if happens or else, not both at the same time
        sub = num2 - num1
        print(sub)

    msg = "Done!"
    return msg
    #return sum           #return will return the value to whatever you called the function

#var = test(3, 8)    #function call
test(3, 8)         # expected = 24  first 1
test(12, 4)        # 3
test(2, -120)      # 5
test(-20, -10)     # 7
test(10, 2)        # 9
test(19283, 91209) # 11
print(test(3, 8))  # 13
#print(sub)
#print(var)
