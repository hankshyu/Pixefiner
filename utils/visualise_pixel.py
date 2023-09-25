import sys
from matplotlib import pyplot as plt
from matplotlib import colors
import numpy as np

data = np.loadtxt(sys.argv[1], delimiter = " ")
# data = np.random.randint(3, size=(50, 50))
# print("done randomize")
# data = [
# [0,0,0,0,0,1,1,1,1,0],
# [0,0,0,0,0,1,0,0,1,0],
# [0,0,1,0,1,0,1,1,0,0],
# [0,0,1,0,0,1,1,0,1,0],
# [0,0,1,0,1,0,0,1,1,0],
# [1,0,0,1,0,1,0,0,1,0],
# [0,1,0,0,0,1,1,1,1,1],
# [0,1,0,0,0,0,1,1,1,1],
# [1,0,0,0,1,1,1,0,1,0],
# [1,1,1,1,0,0,0,1,1,0]
# ]

cmap = colors.ListedColormap(['Blue','red', 'green'])
plt.figure(figsize=(20, 20))
plt.pcolor(data[::-1],cmap=cmap,edgecolors='k', linewidths=0.5)
plt.savefig(sys.argv[2], dpi = 150)