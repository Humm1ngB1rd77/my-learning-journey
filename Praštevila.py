n = int(input("enter any number:"))   #number entered by the user
i = 0
c = 0

while(n != 0):          
    i = 1               #index by which you divide n
    c = 0               #numerator of divisors

    while(i <= n):               
        if(n % i == 0):
            print (n, "is divisible by ", i)
            c = c + 1
        i = i + 1
    if (c == 2):
        print("So",n,"is a prime number")
    else:
        print ("So", n, "is not a prime number")
    n = int(input("enter any number:"))


    