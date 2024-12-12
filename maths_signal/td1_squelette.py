# -*- coding: utf-8 -*-
"""
Created on Tue Sep 19 09:16:26 2023

@author: JDION
"""

import numpy as np
import matplotlib.pyplot as plt

import scipy.io.wavfile as wavfile 
import sounddevice as sd  

from functools import partial

from my_signal import Signal
        
"""
Exercice 4
"""

fqech = 44100
wav_file_path="sound-20241108/forest5s.wav"

"""
Q1
"""

def read_test(wav_file):
    wav_rate, wav_data = wavfile.read(wav_file)
    if (wav_rate == fqech):
        return wav_data
    else :
        print("Error: the sampling rate is not "+str(fqech)+" Hz")
        return None

"""
Q2
"""

def play(wav_data):
    sd.play(wav_data, fqech)
    sd.wait()
    
forest_data = read_test(wav_file_path)
# play(forest_data)  Marche pas parce que les périphériques de lecture et d'enregistrement ne sont pas trouvés

"""
Q3
"""

def plot(data):
    t = np.arange(0, len(data)/fqech, 1/fqech)
    plt.plot(t, data)
    plt.xlabel('Time (s)')
    plt.ylabel('Amplitude')
    plt.title('Sound wave')
    plt.savefig('__pycache__/forest_wave.png')
    return None

plot(forest_data)

"""
Q4
"""

def sinus(freq, t):
    return np.sin(2*np.pi*freq*t)

signal_440 = partial(sinus, 440)
signal = Signal(signal_440, fqech)
signal.play(1)
signal.plot(0, 0.01)

"""
Q5
"""

def chord(frequency_list, t):
    return None


"""
Q6
"""

DTMF_TABLE = {
    '1': [1209, 697],
    '2': [1336, 697],
    '3': [1477, 697],
    'A': [1633, 697],

    '4': [1209, 770],
    '5': [1336, 770],
    '6': [1477, 770],
    'B': [1633, 770],

    '7': [1209, 852],
    '8': [1336, 852],
    '9': [1477, 852],
    'C': [1633, 852],

    '*': [1209, 941],
    '0': [1336, 941],
    '#': [1477, 941],
    'D': [1633, 941],
} 

def DTMF(t):
    return None

    