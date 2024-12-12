import numpy as np
from my_signal import Signal


def f(t):
  t_mod = t % 2
  if t_mod > 1:
    t_mod = 2 - t_mod
  return t_mod

sampling_frequency = 1000
signal = Signal(f, sampling_frequency)

signal.plot(-3, 3)

signal.spectrum(3, acquisition_duration=200, unilateral=True)