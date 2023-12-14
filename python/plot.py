from numpy import *
import pylab as p
import mpl_toolkits.mplot3d.axes3d as p3
import matplotlib.pyplot as plt

delta = 0.1
# u e v são variaveis parametricas
# u is an array from 0 to 2*pi, with 100 elements
# u é um array de 0 até 2*pi com 100 elementos
u=r_[0:2*pi:100j]

# v é um array de 0 até pi com 100 elementos
v=r_[0:pi:100j]

# x, y, e z são coordenadas para plotagem
# cada um é organizado em matrizes de 100x100
x = 8*outer(abs(cos(u)), abs(sin(v)))
y = 8*outer(abs(sin(u)), abs(sin(v)))
z = 8*outer(ones(size(u)), abs(cos(v)))

fig=p.figure()
ax = p3.Axes3D(fig)

# Utilizado para as linhas de contornos
ax.contour3D(x,y,z)

#Retira o plano de fundo dos eixos
ax.set_axis_off()

#É utilizado para mudam o ponto de vista da imagem
ax.view_init(elev=10., azim=85.0)


plt.show()