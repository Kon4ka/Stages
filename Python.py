from pyqtgraph.Qt import QtCore, QtGui, QtWidgets
import pyqtgraph.opengl as gl
import pyqtgraph as pg
import numpy as np
import sys
# -*- coding: utf-8 -*-
import os
import PyQt5
import sys
from PyQt5 import QtGui, QtWidgets, QtCore
import math
import sys


def get_rot_mat(_axis, _angle_rad):
    if _axis == 'x':
        return np.array([[1, 0, 0],
                         [0, math.cos(_angle_rad), math.sin(_angle_rad)],
                         [0, -math.sin(_angle_rad), math.cos(_angle_rad)]])
    if _axis == 'y':
        return np.array([[math.cos(_angle_rad), 0, math.sin(_angle_rad)],
                         [0, 1, 0],
                         [-math.sin(_angle_rad), 0, math.cos(_angle_rad)]])
    if _axis == 'z':
        return np.array([[math.cos(_angle_rad), math.sin(_angle_rad), 0],
                         [-math.sin(_angle_rad), math.cos(_angle_rad), 0],
                         [0, 0, 1]])

    print("get_rot_mat: wrong input")
    exit(-9)


QtCore.QCoreApplication.setAttribute(QtCore.Qt.AA_UseDesktopOpenGL)
app = QtWidgets.QApplication(sys.argv)

w = gl.GLViewWidget()  # Создаем некоторый виджет
w.opts['distance'] = 40  # Дистанция от объекта до наблюдателя
w.resize(1000, 1000)
w.show()
w.setWindowTitle('Pyqtgraph-3D example: GLLinePlotItem')

gx = gl.GLGridItem()  # Сетка
gx.rotate(90, 0, 1, 0)  # Поворачиваем на 90 гр вокруг оси у
gx.translate(-10, 0, 0)  # Смещение не -10 по иксу
w.addItem(gx)  # Добавление виджета
gy = gl.GLGridItem()
gy.rotate(90, 1, 0, 0)  # То же для других осей
gy.translate(0, -10, 0)
w.addItem(gy)
gz = gl.GLGridItem()
gz.translate(0, 0, -10)
w.addItem(gz)

a, e = 5, 0.9  # Задаем переменные для орбиты

psi = math.radians(10)
theta = math.radians(30)
phi = math.radians(50)

coordinates_orig = []
for i in range(361):
    angle = math.radians(i)
    x = a * math.cos(angle)
    y = a * math.sqrt(1 - e ** 2) * math.sin(angle)
    z = 0
    coordinates_orig.append([x, y, z])

coordinates_orig = np.array(coordinates_orig)
plt = gl.GLLinePlotItem(pos=coordinates_orig, color=pg.glColor((360, 10 * 1.3)),
                        width=2, antialias=True)

w.addItem(plt)  # Добавляем элементы в пространство

md = pg.opengl.MeshData.sphere(rows=10, cols=10)                # Создаём и настраиваем сферу
m3 = pg.opengl.GLMeshItem(meshdata=md, smooth=False, shader='balloon', color=(0, 1, 0, 0.2))
w.addItem(m3)
m3.translate(coordinates_orig[0][0], coordinates_orig[0][1], coordinates_orig[0][2])

time_global_i_max = 360
time_global_i = 0
psi_c, theta_c, phi_c = 0, 0, 0
rotation = 0
coordinates = coordinates_orig


def update():
    global coordinates_orig, phi, theta, psi, i, psi_c, theta_c, phi_c, rotation, time_global_i_max, time_global_i,\
        coordinates

    x_curr = -coordinates[time_global_i][0]
    y_curr = -coordinates[time_global_i][1]
    z_curr = -coordinates[time_global_i][2]

    time_global_i = (time_global_i + 1) % time_global_i_max

    if psi_c <= psi:

        rotation = (rotation + 1) % time_global_i_max
        time = math.radians(rotation)
        coordinates = np.dot(coordinates_orig, get_rot_mat('z', time))
        psi_c = time

        if psi_c > psi:
            coordinates_orig = coordinates

    elif theta_c <= theta:

        if theta_c == 0:
            rotation = 0
        rotation = (rotation + 1) % time_global_i_max
        time = math.radians(rotation)
        coordinates = np.dot(coordinates_orig, get_rot_mat('x', time))
        theta_c = time

        if theta_c > theta:
            coordinates_orig = coordinates

    elif phi_c <= phi:

        if phi_c == 0:
            rotation = 0
        rotation = (rotation + 1) % time_global_i_max
        time = math.radians(rotation)
        coordinates = np.dot(coordinates_orig, get_rot_mat('z', time))
        phi_c = time

        if phi_c > phi:
            coordinates_orig = coordinates

    # меняем позицию элипса
    coordinates = np.array(coordinates)
    plt.setData(pos=coordinates, color=(0.255, (time_global_i/2)/10, 0.04, 1), width=3, antialias=True)

    # вычисляем новые координаты шара и перемещаем его
    x_curr = x_curr + coordinates[time_global_i][0]
    y_curr = y_curr + coordinates[time_global_i][1]
    z_curr = z_curr + coordinates[time_global_i][2]

    m3.translate(x_curr, y_curr, z_curr)


timer = QtCore.QTimer()
timer.timeout.connect(update)  # Запуск таймера
timer.start(50)

sys.exit(app.exec_())  # Запускаем цикл обработки событий
