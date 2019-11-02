#%%
import matplotlib.pyplot as plt
import matplotlib as mpl
import numpy as np

#%%
fm = 2 
t = np.linspace(0, 1, 100)
A = 2*np.cos(2*np.pi*2*t) 
# plt.plot(t,A)
# plt.show() 

#%%
C = np.cos(2*np.pi*8*t)
# plt.plot(t,C)
# plt.show() 

# %%
AM = ( A + 2 ) * C
# plt.plot(t,AM)
# plt.show() 

# %%
plt.plot(t,A + 2,color = "red",)
plt.plot(t,AM)
#plt.plot(t,C)
plt.plot(t,-(A + 2),color = "red")
plt.legend()
# %%
