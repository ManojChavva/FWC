


import sys                                          #for path to external scripts
sys.path.insert(0,'/home/manoj/Documents/CoordGeo')         #path to my scripts

#Code by GVV Sharma (works on termux)
#January 18, 2022
#License
#https://www.gnu.org/licenses/gpl-3.0.en.html
#To verify if the given vertices belong to an isosceles triangle


#Python libraries for math and graphics
import numpy as np
import matplotlib.pyplot as plt
from numpy import linalg as LA


#local imports
from line.funcs import *
from triangle.funcs import *
from conics.funcs import circ_gen
from sympy import symbols,Eq,solve
#if using termux
import subprocess
import shlex
#end if

#Input parameters

B = np.array(([0,2])) #B[0] B[1]
C = np.array(([0,-2])) #C[0] C[1]
O = np.array(([0,0]))


                    
A_x = (B[0]+C[0]-(np.sqrt(3)*(C[1]-B[1])))/2 # This computes the x coordinate of the third vertex.
A_y = (B[1]+C[1]+np.sqrt(3)*(C[0]-B[0]))/2 #This computes the 'y coordinate' of the third vertex. 
A = np.array([A_x, A_y]) #This is point z, the third vertex. 

print(A)


D_x = (B[0]+C[0]+(np.sqrt(3)*(C[1]-B[1])))/2 # This computes the x coordinate of the third vertex.
D_y = (B[1]+C[1]-np.sqrt(3)*(C[0]-B[0]))/2 #This computes the 'y coordinate' of the third vertex. 
D = np.array([D_x, D_y]) #This is point z, the third vertex. 
print(D)
#Generating all lines
x_AB = line_gen(A,B)
x_BC= line_gen(B,C)
x_CA = line_gen(C,A)
x_BO = line_gen(B,A)
x_BD = line_gen(B,D)
x_CD = line_gen(C,D)

#Plotting all lines
plt.plot(x_AB[0,:],x_AB[1,:])
plt.plot(x_BC[0,:],x_BC[1,:])#,label='$Diameter$')
plt.plot(x_CA[0,:],x_CA[1,:])#,label='$Diameter$')
plt.plot(x_BO[0,:],x_BO[1,:])#,label='$Diameter$')
plt.plot(x_BD[0,:],x_BD[1,:],linestyle='dashed')#,label='$Diameter$')
plt.plot(x_CD[0,:],x_CD[1,:],linestyle='dashed')#,label='$Diameter$')
#
#
#Labeling the coordinates
tri_coords = np.vstack((A,B,C,O,D)).T
plt.scatter(tri_coords[0,:], tri_coords[1,:])
vert_labels = ['A(x,y)','B(0,a)','C(0,-a)', 'O(0,0)', 'A1(-x,y)']
for i, txt in enumerate(vert_labels):
    plt.annotate(txt, # this is the text
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(18,20), # distance from text to points (x,y)
                 ha='center') # horizontal alignment can be left, right or center

plt.xlabel('$x$')
plt.ylabel('$y$')
plt.grid() # minor
#plt.axis('equal')
plt.axis([-4,4.5,-3,3])


plt.savefig('/home/manoj/git/FWC/Matrix/line/triangle.png')

plt.savefig('/home/manoj/git/FWC/Matrix/line/code-py/triangle.pdf')
plt.show()
