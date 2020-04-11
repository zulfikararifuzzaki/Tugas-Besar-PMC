from output import *

screen = Tk();
#screen.geometry('900x900')
screen.title("Gambar Rangkaian");

canvas = Canvas(screen, width=1500, height=600);
canvas.pack()
def quit() :
    screen.destroy();
b1 = Button(screen, text = "Show Equivalent Circuit",width=30,command=createEquiCircuit)
b2 = Button(screen, text = "Show Circuit",width=30,command=createCircuit)
b3 = Button(screen, text = "Generate Equivalent Graphic",width=30,command=generateEquiGraph)
b4 = Button(screen, text = "Generate Graphic",width=30,command=lambda : generateGraph("V"))#gk bisa letakkan parameter sebagai command
b_quit = Button(screen, text = "Quit",width=30,command=quit)
b1.place(relx = 0.1, rely = 0.1, anchor = CENTER)
b2.place(relx = 0.1, rely = 0.15, anchor = CENTER)
b3.place(relx = 0.1, rely = 0.2, anchor = CENTER)
b4.place(relx = 0.1, rely = 0.25, anchor = CENTER)
b_quit.place(relx = 0.1, rely = 0.3, anchor = CENTER)
mainloop()
