def test(num1, num2):    #function signature
    #print(num1, num2, num1 + num2)    #displays
    if num1 > num2 == True:    #conditional, jump inside this block if num1 > num2 == true
        sum = num1 + num2
        print(sum)           #return will return the value to whatever you called the function
    else:    #either if happens or else, not both at the same time
        sub = num2 - num1
        print(sub)
    #return sum           #return will return the value to whatever you called the function

#var = test(3, 8)    #function call
test(3, 8)
test(12, 4)
test(19283, 91209)
#print(var)
