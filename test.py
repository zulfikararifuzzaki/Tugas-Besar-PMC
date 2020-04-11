from tkinter import Tk, Toplevel, Button

def login():
    top = Toplevel(root)
    Button(top, text="Quit", command=top.destroy).pack()
    top.grab_set() # deactivate the main GUI while top is opened
    root.wait_window(top) # wait for top to be closed before doing the rest
    print("logged in")

root = Tk()

Button(root, text="login", command=login).pack()

root.mainloop()