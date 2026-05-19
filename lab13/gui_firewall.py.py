import tkinter as tk
from tkinter import ttk
import psutil

def refresh_data():
    for i in tree.get_children():
        tree.delete(i)
    for conn in psutil.net_connections()[:20]:
        port = conn.laddr.port if conn.laddr else "N/A"
        tree.insert("", "end", values=(port, conn.status, conn.type))

root = tk.Tk()
root.title("My Firewall Monitor")
root.geometry("500x400")

tree = ttk.Treeview(root, columns=("Port", "Status", "Type"), show="headings")
tree.heading("Port", text="Port")
tree.heading("Status", text="Status")
tree.heading("Type", text="Type")
tree.pack(fill="both", expand=True)

btn = tk.Button(root, text="Refresh Ports", command=refresh_data)
btn.pack()

refresh_data()
root.mainloop()
