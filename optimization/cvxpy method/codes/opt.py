#Code by Amey Waghmare, 
#Jan 16, 2020
#Revised by GVV Sharma
#Jan 17, 2020
#Released under GNU GPL
#Quadratic program example
#using cvx
import numpy as np
from cvxpy import *


#function parameters
P = np.array([2,3.14])    
V = np.array([[1,0],[0,3.14]])
u = np.array([0,0]).reshape(2,-1)

x = Variable((2,1))

#function
f =  quad_form(x,V)
obj = Minimize(f)

#Constraints

constraints = [P@x-25 == 0]
#solution
Problem(obj, constraints).solve()

print((f.value),x.value)


