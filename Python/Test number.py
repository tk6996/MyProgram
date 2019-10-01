#%%
import numpy as np
#%%
id = '1234567890121'
a = np.array(list(id[:12]),dtype = int)
#%%
b = np.arange(13,1,-1)
#%%
b
#%%
x = np.sum(a*b) % 11
x
#%%
1 - x if x <= 1 else 11 - x

#%%


#%%
