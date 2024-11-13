# -*- coding: utf-8 -*-
"""
Created on Tue Sep 19 09:16:26 2023

@author: JDION
"""


"""
Création de la classe Signal utilisée durant l'intégralité de ce cours
"""


import numpy as np
import matplotlib.pyplot as plt
import sounddevice as sd

class Signal:
    
    
    def __init__(self, function, sampling_frequency):
        
        """
        Initialise une instance de la classe Signal.
    
        Args:
            function (callable): Une fonction qui définit le comportement du signal. La fonction doit accepter un argument (le temps) et retourner la valeur du signal à cet instant.
            sampling_frequency (float): La fréquence d'échantillonnage du signal en hertz.
    
        Returns:
            None
    
        Example:
            Pour créer une instance de Signal avec une fonction sinus et une fréquence d'échantillonnage de 1000 Hz :
            
            signal = Signal(np.sin, 1000)
        """
        
        
        self.function = function
        self.sampling_frequency = sampling_frequency
        

    def evaluate(self, t):
        
        """
        Évalue le signal à un instant donné.
    
        Args:
            t (float): Le temps auquel évaluer le signal en secondes.
    
        Returns:
            float: La valeur du signal à l'instant t.
            
        Example:
            Pour évaluer le signal à t = 2.5 secondes :
            
            value = signal.evaluate(2.5)
        """
        
        return self.function(t)
    
    
    def samples(self, start_time, end_time):
        
        """
        Échantillonne le signal dans la plage de temps spécifiée.

        Args:
            start_time (float): Le temps de début de l'échantillonnage en secondes.
            end_time (float): Le temps de fin de l'échantillonnage en secondes.

        Returns:
            list: Une liste des échantillons du signal dans la plage de temps spécifiée.
        
        Example:
            Pour échantillonner le signal entre 0 et 10 secondes :
            
            signal.samples(0, 10)
        """
        
        return None
    

    def plot(self, start_time, end_time):
        
        """
        Affiche la représentation graphique du signal sur une plage de temps donnée.
    
        Args:
            start_time (float): Le temps de début de la représentation en secondes.
            end_time (float): Le temps de fin de la représentation en secondes.
    
        Returns:
            None
    
        Notes:
            Cette méthode génère un graphique affichant le signal dans la plage de temps spécifiée. Le graphique inclut des étiquettes d'axe pour le temps et l'amplitude, ainsi qu'un titre "Représentation du signal". La méthode affiche également une grille pour une meilleure lisibilité.
        
        Example:
            Pour afficher le signal entre 0 et 10 secondes :
            
            signal.plot(0, 10)
        """        
        
        return None
        
    
    def play(self, duration):
        
        """
        Joue le son associé au signal pendant la durée spécifiée.

        Args:
            duration (float): La durée en secondes pendant laquelle jouer le son.

        Returns:
            None
        """

        sd.play(self.samples(0, duration), self.sampling_frequency)
        sd.wait()
        