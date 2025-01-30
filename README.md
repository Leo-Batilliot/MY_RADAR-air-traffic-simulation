# MY_RADAR  
## DESCRIPTION  
  
my_radar is a 2d air traffic simulator, it takes a file as an argument and renders said file in a 2d csfml interface
the simulation consist of 2 parts :  
- rendering the planes during their flight (only when they are in the air)
- checking collisions between planes (if they are not under a control tower) and deleting if they collide.

## FILE FORMAT  
  
the size of the simulation is around 1800 by 1000.  
The position should be between those values, they should be formated as int or float.  
The program starts lagging when you run it with more than a million planes be careful.  
the file has to contain 2 types of lines :  
  
lines describing airplanes formated like this :  
A <takeoff_x_position> <takeoff_y_position> <landing_x_positon> <landing_y_positon> <speed(pixels/second)> <takeoff_time(seconds)>  
Exemple : A 1459 786 897 77 257 0.08  
  
And lines describing towers formated like this :  
T <x_position> <y_position> <tower_radius>  
Exemple : T 723 234 50  

if you don't have such a file and you just want to render a random simulation you can use ./generator <number_of_planes> <number_of_towers>  
the file will be generated as src/file.txt and you can run ./my_radar src/file.txt to try it out.  

## RADAR USAGE

You can use the simulation by runing make and ./my_radar <link_to_your_file>  
You can also use ./my_radar -h for more informations about the simulation and the keys you can use.  
