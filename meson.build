project('Raylib Game', 'C')

add_project_arguments('-std=c23' ,language: 'C')

ray = dependency('raylib')
ray_deps = ['-lX11', '-lpthread', '-lm', '-ldl', '-lrt']

core_src = ['src/core/main.c']
gameplay_src = ['src/gameplay/game.c', 
                'src/gameplay/objects.c']
graphics_src = ['src/graphics/render.c']
objects_src = [ 'src/objects/circle.c',
                'src/objects/background.c',
                'src/objects/stats.c']

core_inc = include_directories('src/core')
gameplay_inc = include_directories('src/gameplay')
graphics_inc = include_directories('src/graphics')
utils_inc = include_directories('src/graphics')
objects_inc = include_directories('src/objects')

source = [core_src, gameplay_src, graphics_src, objects_src]
include = [core_inc, gameplay_inc, graphics_inc, utils_inc, objects_inc]

executable('game', source, dependencies: ray, include_directories: include, link_args: ray_deps)
