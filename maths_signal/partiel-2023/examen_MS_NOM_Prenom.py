# -*- coding: utf-8 -*-
"""
Created on Tue Sep 19 09:16:26 2023

@author: JDION
"""

import numpy as np
import matplotlib.pyplot as plt
from my_signal import Signal        
        
"""
Partie 1
"""

"""
Q2
"""

def s(t):
    t = t % 2
    return np.exp(-t) if t > 0 and t < 1 else np.exp(t-2)

sampling_frequency = 1000
s = Signal(s, sampling_frequency)
s.plot(-5, 5, sampled=True)

"""
Partie 2
"""

"""
Q2b
"""



"""
Partie 3
"""

"""
Q5 (Bonus)
"""



"""
Partie 4
"""

"""
Q1
"""



"""
Partie 5
"""

"""
Q2
"""

def read_S():
    St = np.genfromtxt('S.csv', delimiter='')
    return St

signalS_data = read_S()
