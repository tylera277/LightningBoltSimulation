# 10 Jun 2023

# Program: Want to export the potential values out of c++ program
# and plot them on some kind of heat map using this python script

from matplotlib import pyplot as plt

import pandas as pd

import numpy as np


potential_data = pd.read_csv('../outputData/10jun2023_data.csv')
new_pot_data = potential_data.dropna()



print(potential_data.head())

x_size = 100
y_size = 100

new_pot_data_numpy = (new_pot_data.to_numpy())
new_pot_data_numpy = new_pot_data_numpy[0:(5*y_size)+y_size, 0:(x_size)].astype(float)



print(new_pot_data_numpy)
print("SIZE:", new_pot_data_numpy.shape)
for i in range(0,1,1):
    plt.imshow(new_pot_data_numpy[(y_size*i):(y_size*i)+y_size, (x_size*i):(x_size*i)+x_size], cmap='hot', interpolation='nearest')
    plt.show()

