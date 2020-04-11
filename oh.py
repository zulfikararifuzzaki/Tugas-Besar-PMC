from tkinter import *
import random
root = Tk()

class Recta:

    def __init__(self, height=60, width=80):
        self.height = height
        self.width = width
        self.create_buttons()
        self.canvas = Canvas(root)
        self.canvas.pack()


    def create_buttons(self):
        self.frame = Frame(root, bg='grey', width=400, height=40)
        self.frame.pack(fill='x')

        self.button1 = Button(self.frame, text='Add Rect', command=self.randomRects)
        self.button1.pack(side='left', padx=10)
        self.button2 = Button(self.frame, text='Remove Rect', command=self.randomRects)
        self.button2.pack(side='left')


    def randomRects(self):
        w = random.randrange(300)
        h = random.randrange(200)
        self.canvas.create_rectangle(0, 0, w, h, fill='green')


tes = Recta()
root.mainloop()