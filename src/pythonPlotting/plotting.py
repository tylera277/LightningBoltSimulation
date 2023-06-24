# 10 Jun 2023

# Program: Want to export the potential values out of c++ program
# and plot them on some kind of heat map using this python script

from matplotlib import pyplot as plt

import pandas as pd

import numpy as np


# Select which output file you want to read,
# either potential or boundary condition values
#potential_data = pd.read_csv('../outputData/24jun2023_pot_data.csv')
potential_data = pd.read_csv('../outputData/24jun2023_BC_data.csv')


new_pot_data = potential_data.dropna()

a = np.array(([1, 2],
              [3, 4]))

print(a[1,0])

print(potential_data.head())

x_size = 250
y_size = 250

new_pot_data_numpy = (new_pot_data.to_numpy())
print("SIZE:", new_pot_data_numpy.shape)
new_pot_data_numpy = new_pot_data_numpy[0:(5*y_size)+y_size, 0:(x_size)].astype(float)



print(new_pot_data_numpy)

for i in range(0,4,1):
    plt.imshow(new_pot_data_numpy[(y_size*i):(y_size*i)+y_size-1, 0:x_size], cmap='hot', interpolation='nearest')
    plt.show()

