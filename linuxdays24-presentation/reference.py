#!/usr/bin/python3

import math
import timeit

##############################
# Generate data
def generate_input(n):
    l = []
    a = 2
    b = 2
    for t in range(n):
        l.append((a, b, a + b - 1))
        if t % 2 == 0:
            a += 1
        else:
            b += 1

    return l

NUM_TRIANGLES = 5000
generated_triangles = generate_input(NUM_TRIANGLES)
for t in generated_triangles:
    if t[0] + t[1] < t[2] or t[0] + t[2] < t[1] or t[1] + t[2] < t[0]:
        raise Exception("error, this is not a triangle: " + str(t))
# print(len(generated_triangles))
# print(generated_triangles)

##############################


##############################
# Implementation in python
def python_area(triangles, coef_a=1, coef_b=1, coef_c=1):
    def compute_area(a, b, c):
        # Poloviční obvod
        s = (a + b + c) / 2
        # Heronův vzorec pro plochu
        return math.sqrt(s * (s - a) * (s - b) * (s - c))
    sum_area = 0
    for t in triangles:
        a, b, c = t
        # Přenásobíme strany odpovídajícími koeficienty
        a *= coef_a
        b *= coef_b
        c *= coef_c
        # Spočítáme plochu a přidáme ji k celkové sumě
        sum_area += compute_area(a, b, c)
    return sum_area

##############################
# Measurement
coef_a = 2
coef_b = 2
coef_c = 2
def test():
    vysledek = python_area(triangles, coef_a, coef_b, coef_c)

with open("reference-results.txt", "w") as f:
    for n in range(NUM_TRIANGLES):
        triangles = generated_triangles[:n]
        f.write(str(n + 1) + "," + str(sum(timeit.repeat(test, number=1, repeat=10))/10) + "\n")

#print("Sum of area: " + str(python_area(triangles, coef_a, coef_b, coef_c)))

