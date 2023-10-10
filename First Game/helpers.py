import utilities
import random
from tkinter import Canvas, Tk
import time



def make_panda(canvas, center, size=50,my_tag = None):
    #make ears
    utilities.make_circle(canvas,(center[0] + size/2,center[1] - size), size/3.5,color = 'black',tag=my_tag)
    utilities.make_circle(canvas,(center[0] - size/2,center[1] - size), size/3.5,color = 'black',tag=my_tag)
    #make body
    utilities.make_oval(canvas,(center[0], center[1] + size * 2), size*1.5, size*1.65, color = 'white', tag = my_tag)
    utilities.make_oval(canvas,(center[0],center[1] + size*2.8), size*1.2, size/1.2, color = 'black', tag = my_tag)
    #make head
    utilities.make_circle(canvas, center, size, color='white', tag=my_tag)
    #make eyes
    left_eye_pos = (center[0] - size / 4, center[1] - size / 5)
    right_eye_pos = (center[0] + size / 4, center[1] - size / 5)
    eye_width = eye_height = size / 10
    utilities.make_oval(canvas, left_eye_pos, eye_width, eye_height, color='black', tag=my_tag, outline = 'white')
    utilities.make_oval(canvas, right_eye_pos, eye_width ,eye_height, color='black', tag=my_tag, outline = 'white')
    utilities.make_line(canvas, [
        (center[0] - size / 2, center[1] + size / 3),
        (center[0], center[1] + size / 1.2),
        (center[0] + size / 2, center[1] + size / 3)
    ], curvy=True, tag=my_tag)
    #make nose
    utilities.make_nose(canvas,(center[0], center[1] + size/8) ,size/4, tag = my_tag)

def make_bamboo(canvas, center, tag = None):
    rand_length = int((random.randint(200,400)/random.randint(1,4)) // 1)
    rand_distance = random.randint(10,15)
    utilities.make_rectangle(canvas,(center),8,rand_length,color = 'limegreen',tag = tag)
    for i in range(0,rand_length,20):
        utilities.make_rectangle(canvas,(center[0],center[1] - i), 8, 5, color = 'darkgreen', tag = tag)

def make_cloud(canvas, center, size = 50, tag = None):
    utilities.make_oval(canvas, center,size,size/2, color = 'white', tag = tag)
    
