import numpy
from matplotlib import pyplot as plt

x = numpy.loadtxt("result.dat", usecols=0)
y = numpy.loadtxt("result.dat", usecols=1)
with open("sun.dat", "r") as inp:
    sun_coord = inp.readline().split()
    x0, y0 = float(sun_coord[0]), float(sun_coord[1])
plt.hist2d(x, y, bins=(100, 100), cmap=plt.cm.jet)
plt.gca().add_patch(plt.Circle((x0, y0), radius=2, color="red"))
plt.gca().set_aspect("equal", adjustable="box")
plt.savefig("res.pdf")
plt.show()
