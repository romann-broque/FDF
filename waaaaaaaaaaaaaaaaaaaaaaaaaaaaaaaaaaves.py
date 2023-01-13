from math import cos, sin

SIZE = 60
SCALE = 5.0
AMPLITUDE = 12
for y in range(SIZE):
	print(*[round(AMPLITUDE * (sin(y / SCALE) + cos(x / SCALE))) for x in range(SIZE)])
