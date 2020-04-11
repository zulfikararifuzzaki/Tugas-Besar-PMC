import tkinter as tk

# --- functions ---

def on_click():
    # change image on canvas
    canvas.itemconfig(image_id, image=image2)

# --- main ---

root = tk.Tk()

# canvas for image
canvas = tk.Canvas(root, width=60, height=60)
canvas.pack()

# button to change image
button = tk.Button(root, text="Change", command=on_click)
button.pack()

# images
image1 = tk.PhotoImage(file="ggg1.png")
image2 = tk.PhotoImage(file="ggg2.png")

# set first image on canvas
image_id = canvas.create_image(0, 0, anchor='nw', image=image1)

root.mainloop()