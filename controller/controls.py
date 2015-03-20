#!/bin/python
"""
Module to capture controller input

March 13th, 2015
"""

import pygame


class Controller():
    def __init__(self):
        # Initializing the controller
        pygame.init()
        self.joystick = pygame.joystick.Joystick(0)
        self.joystick.init()
        # Storing controller details
        self.num_axes = self.joystick.get_numaxes()
        self.num_buttons = self.joystick.get_numbuttons()
        self.num_hats = self.joystick.get_numhats()

    def get_degrees(self, get_function, degree):
        degrees = [0 for x in range(degree)]
        pygame.event.pump()
        for i in range(len(degrees)):
            degrees[i] = get_function(i)
        return degrees

    def get_axes(self):
        # Returns values of all axes
        return self.get_degrees(self.joystick.get_axis, self.num_axes)

    def get_buttons(self):
        # Returns values of all buttons
        return self.get_degrees(self.joystick.get_button, self.num_buttons)

    def get_hats(self):
        # Returns values of all hats
        return self.get_degrees(self.joystick.get_hat, self.num_hats)



if __name__ == '__main__':
    controller = Controller()
    while True:
        print controller.get_hats()



