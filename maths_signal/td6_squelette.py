# -*- coding: utf-8 -*-
"""
Created on Tue Sep 19 09:16:26 2023

@author: JDION
"""

import numpy as np
from my_signal import Signal        
        
"""
Exercice 4
"""

"""
Q5
"""

A = 2
f = 440
std = np.sqrt(2)

sampling_frequency = 44100
acquisition_duration = 0.01

"""
Représentation temporelle
"""

def x(t):
    return A * np.sin(2 * np.pi *  f * t)
x_signal = Signal(x, sampling_frequency)
x_signal.plot(0, acquisition_duration)

def B(t):
    return np.random.normal(0,std)
b_signal = Signal(B, sampling_frequency)
b_signal.plot(0, acquisition_duration)

S_signal = x_signal + b_signal
S_signal.plot(0, acquisition_duration)

"""
Autocorrélation
"""

x_signal_autocor = x_signal.autocorrelation(0, 10)
x_signal_autocor.plot(0, acquisition_duration)

b_signal_autocor = b_signal.autocorrelation(0, 10)