import pygame
import math
import time
from typing import Tuple

Point = tuple

WIDTH = 900
HEIGHT = 600
BLACK = (255, 255, 255)
WHITE = (0, 0, 0)
DELAY = 0.5
ROOT = (450, 550)
DEPTH = 9

pygame.init()
display = pygame.display.set_mode([WIDTH, HEIGHT])
pygame.display.set_caption("Fractal Tree")
screen = pygame.display.get_surface()


def input(event):
    if event.type == pygame.QUIT:
        exit()


def event_loop():
    while True:
        input(pygame.event.wait())


def refresh():
    pygame.display.flip()


def draw_line(beg: Point, end: Point):
    pygame.draw.line(screen, BLACK, beg, end, 2)


def delay():
    time.sleep(DELAY)


def get_y2(y1, theta, depth):
    return y1 + int(math.sin(math.radians(theta)) * depth * 10)


def get_x2(x1, theta, depth):
    return x1 + int(math.cos(math.radians(theta)) * depth * 10)


def get_end(beg: Point, theta, depth):
    x2 = get_x2(beg[0], theta, depth)
    y2 = get_y2(beg[1], theta, depth)
    return {"node": (x2, y2), "angle": theta}


def draw_child(beg: Point, theta, depth):
    end = get_end(beg, theta, depth)
    refresh()
    draw_line(beg, end["node"])
    delay()
    return end


def draw_children(beg: Point, theta, depth, layer):
    ch_1 = draw_child(beg, theta - 20, depth)
    ch_2 = draw_child(beg, theta + 20, depth)
    layer.append(ch_1)
    layer.append(ch_2)


def draw_tree(root: Point, theta, depth):
    nodes = [{"node": root, "angle": theta}]

    while depth > 0:
        next_layer = []

        for node in nodes:
            draw_children(node["node"], node["angle"], depth, next_layer)

        depth = depth - 1
        nodes = next_layer


if __name__ == '__main__':
    draw_tree(ROOT, -90, DEPTH)
