#!/usr/bin/env python3
#  tasks.py
#  gpcu
#
#  Created by Evan Elias Young on 2019-01-24.
#  Copyright 2019 Evan Elias Young. All rights reserved.

from invoke import task

@task
def lint(c):
    c.run('cpplint main.cpp')

@task
def compile(c):
    c.run('g++ -std=c++11 main.cpp -O -o main.exe')

@task
def build(c):
    c.run('build.py')

@task
def run(c):
    c.run('main.exe')
