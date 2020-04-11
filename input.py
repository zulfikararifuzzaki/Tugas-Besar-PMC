from tkinter import *
window = Tk() 
window.geometry('900x900')
button = Button(m, text='Stop', width=25, command=m.destroy) 
button.grid() 
mainloop()