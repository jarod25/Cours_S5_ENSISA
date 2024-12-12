import numpy as np
from my_signal import Signal

def P(t):
    if abs(t) <= 1/2:
        return 1 
    else: 
        return 0

# signal = Signal(P, 1000)
# signal.plot(-10, 10)
# signal.spectrum(10, acquisition_duration=10, fourier_transform=True)

def triangle(t):
    if  abs(t) <= 1/2:
        return 1-(2*abs(t))
    else :
        return 0


def T(t):
    if abs(t) <= 1/2 and t >= 0:
        return -2 * t + 1
    elif abs(t) <= 1/2 and t < 0:
        return 2 * t + 1
    return 0

# signal2 = Signal(triangle, 1000)
# signal2.plot(-10, 10)
# signal2.spectrum(10, acquisition_duration=10, fourier_transform=True)

signal3 = Signal(T, 1000)
signal3.plot(-10, 10)
signal3.spectrum(10, acquisition_duration=10, fourier_transform=True)

def     