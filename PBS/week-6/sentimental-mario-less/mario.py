import cs50
import sys

height = cs50.get_int("Height: ")

while height <= 0 or height > 8:
    height = cs50.get_int("Height: ")

for i in range(height):
    for s in range(height - i - 1):
        sys.stdout.write(" ")
        sys.stdout.flush()
    for j in range(i + 1):
        sys.stdout.write("#")
        sys.stdout.flush()
    print("")
