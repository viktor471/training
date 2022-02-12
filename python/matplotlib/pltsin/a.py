# mporting the required modules 
import matplotlib.pyplot as plt 
import numpy as np 
import math 

# setting the x - coordinates 
x = np.arange(-2*(np.pi), 2*(np.pi), 0.1) 
# setting the corresponding y - coordinates 
#y = (( 2/3 + x )**1/2)/x
#y = math.sin(x)  # не работает
#y = np.sin(x);
y = 1/(x + 1)
# potting the points 
plt.plot(x, y) 
      
# function to show the plot 
plt.show()
