#!/usr/bin/env python3
###
#  @file      tasks.py
#  @brief     Defines tasks the help the build process for the task runner.
#
#  @author    Evan Elias Young
#  @date      2019-01-24
#  @date      2019-01-29
#  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
##

from invoke import task

@task
def lint(c):
    c.run('cpplint main.cpp')

@task
def compile(c, headers = False):
    if headers:
        c.run('g++ -std=c++11 -c includes/*.hpp')
    c.run('g++ -std=c++11 main.cpp -O -o main.exe')

@task
def clean(c):
    c.run('rm -rf main.exe')
    c.run('rm -rf includes/*.hpp.gch')

@task
def build(c):
    c.run('build.py')

@task
def run(c, external = False):
    if external:
        c.run('start main.exe')
    else:
        c.run('main.exe')
