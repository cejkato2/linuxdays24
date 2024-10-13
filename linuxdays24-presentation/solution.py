#!/usr/bin/python3

import ldpymod
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
# Measurement
coef_a = 2
coef_b = 2
coef_c = 2
def test():
    obj = ldpymod.LinuxDaysObj()
    result = obj.area(triangles, coef_a, coef_b, coef_c)
    
with open("solution-results.txt", "w") as f:
    for n in range(NUM_TRIANGLES):
        triangles = generated_triangles[:n]
        f.write(str(n + 1) + "," + str(sum(timeit.repeat(test, number=1, repeat=10))/10) + "\n")

#print(timeit.timeit(test, number=100))

#obj = ldpymod.LinuxDaysObj()
# print("Sum of area: " + str(obj.area(triangles, coef_a, coef_b, coef_c)))
