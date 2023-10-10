from tkinter import Canvas, Tk
import helpers
import utilities
import helpers
import time
import random

gui = Tk()
gui.title('My Terrarium')

# initialize canvas:
window_width = gui.winfo_screenwidth()
window_height = gui.winfo_screenheight()
canvas = Canvas(gui, width=window_width, height=window_height, background='forestgreen')
canvas.pack()
canvas.focus_set()

########################## YOUR CODE BELOW THIS LINE ##############################
#environment
utilities.make_rectangle(canvas,(window_width,window_height*.25),window_width,window_height*.25,color='skyblue', tag = 'sky')
utilities.make_oval(canvas, (window_width*.8, window_height*.5), 80, 160, 'cornflowerblue', tag = 'pond')
utilities.make_oval(canvas, (window_width*.85, window_height*.4), 60, 70, 'cornflowerblue', tag = 'pond')
clouds = []

for i in range(10):
    rand_x = random.randint(0,window_width)
    rand_y = random.randint(0,(window_height*.2) // 1)
    helpers.make_cloud(canvas, (rand_x, rand_y), tag='cloud_' + str(i))
    tag = 'cloud_' + str(i)
    clouds.append((tag,random.uniform(1,5)))

#render basics
for i in range(5):
    rand_x = random.randint(0,window_width)
    rand_y = random.randint(300,window_height)
    rand_size = random.randint(30,70)
    helpers.make_panda(canvas, (rand_x,rand_y), rand_size, my_tag = 'panda_' + str(i))
for i in range(5):
    rand_x = random.randint(0,window_width)
    rand_y = random.randint(300,window_height)
    rand_size = random.randint(30,70)
    helpers.make_bamboo(canvas, (rand_x,rand_y), tag = 'bamboo_' + str(i))
#button assignments
LEFT_CLICK = '<Button-1>'
MIDDLE_CLICK = '<Button-2>'
RIGHT_CLICK = '<Button-3>'
MOUSE_DRAG = '<B1-Motion>'
KEY_PRESS = '<Key>'
active_tag = None

#interactions
def select_creature(event):
    global active_tag
    active_tag = utilities.get_tag_from_x_y_coordinate(canvas, event.x, event.y)
    print(active_tag)

def move_creature(event):
    if event.keysym == "w":
        utilities.update_position_by_tag(canvas, tag='player', x=0, y=-10)
    elif event.keysym == "a":
        utilities.update_position_by_tag(canvas, tag='player', x=-10, y=0)
    elif event.keysym == "d":
        utilities.update_position_by_tag(canvas, tag='player', x=10, y=0)
    elif event.keysym == "s":
        utilities.update_position_by_tag(canvas, tag='player', x=0, y=10)

helpers.make_panda(canvas, (200, 200),my_tag = 'player')

bamboo_counter = 5
def add_new_bamboo(event):
    print(event.x, event.y)
    global bamboo_counter
    helpers.make_bamboo(canvas,(event.x, event.y),tag = 'bamboo_' + str(bamboo_counter))
    bamboo_counter += 1        

panda_counter = 5
def add_new_panda(event):
    print(event.x, event.y)
    global panda_counter
    rand_size = random.randint(20,70)
    helpers.make_panda(canvas,(event.x, event.y), size = rand_size, my_tag = 'panda_' + str(panda_counter))
    panda_counter += 1
    
def remove_element(event):
    tag = utilities.get_tag_from_x_y_coordinate(canvas, event.x, event.y)
    if tag == 'pond' :
        print("Panda's need water!")
    elif tag == 'sky':
        print("You can't delete the sky!")
    elif tag == 'text':
        print("You can't delete your help!")
    elif tag == 'player':
        print("You can't delete your player!")
    else:
        utilities.delete_by_tag(canvas, tag)
        print(tag)

def move_element(event):
    if not active_tag:
        print('no tag selected')
        return

    # calculate the current position of the current shape:
    width = utilities.get_width(canvas, active_tag)
    height = utilities.get_height(canvas, active_tag)
    left = utilities.get_left(canvas, active_tag)
    top = utilities.get_top(canvas, active_tag)
    current_x = left + (width / 2)
    current_y = top + (height / 2)

    # calculate the delta of the current shape:
    delta_x = -1 * (current_x - event.x)
    delta_y = -1 * (current_y - event.y)

    # move the shape:
    utilities.update_position_by_tag(canvas, active_tag, x=delta_x, y=delta_y)

#text
canvas.create_text(
    (window_width / 2, 100), 
    text='Left click to create bamboo. Right-click to create pandas. Middle click to delete elements', 
    font=("Purisa", 22)
, tag = 'text')
canvas.create_text(
    (window_width / 2, 130), 
    text="Feed the pandas!", 
    font=("Purisa", 22)
, tag = 'text')


canvas.bind(LEFT_CLICK, add_new_bamboo)
canvas.bind(MIDDLE_CLICK, remove_element)
canvas.bind(RIGHT_CLICK, add_new_panda)
canvas.bind(MOUSE_DRAG, move_element)
canvas.bind(KEY_PRESS, move_creature)

while True:
    for cloud in clouds:
        rand_y = random.randint(0,300)
        cloud_tag = cloud[0] # load the shape's tag
        cloud_speed = random.uniform(.5,1) # load the shape's speed

        # if one of our shapes reaches the "right" of the canvas
        if utilities.get_right(canvas, cloud_tag) > window_width + utilities.get_width(canvas, cloud_tag):
            # then calculate a new position at the "left" of the canvas
            reset_position = -window_width - utilities.get_width(canvas, cloud_tag)
            # and move the shape with that tag to that "left" of the canvas
            utilities.update_position_by_tag(canvas, tag=cloud_tag, x=reset_position)

        # regardless move the shape a little bit (determined by its speed)
        utilities.update_position_by_tag(canvas, tag=cloud_tag, x=cloud_speed, y=0)
    gui.update()
    time.sleep(0.002)

########################## YOUR CODE ABOVE THIS LINE ##############################

# makes sure the canvas keeps running:
canvas.mainloop()
