ece382_lab08
============

[Lab 8 - Robot Maze](http://ece382.com/labs/lab8/index.html)

##Prelab
I am going to be ambitious here: my robot will be able to solve any path maze. By that, I meand that I am not going to hard code "left turn first, then right turn, ect." Instead, I am going to make a robot that goes straight until it sees a wall and then makes an educated decision on turning. Furthermore, it will do this with using the IR sensors (and the nice library I made!) and will do it quickly. I am pretty excited about this.

To start with, I will need a battle plan. Now, one of the key requirements is not hitting a wall. Stopping when a wall is straigth ahead is easy; the more difficult part is to avoid drifting into a wall instead of going straight. To avoid this, I am going to modify my library to have a function that returns which sensor - left or right - is closest to the wall, and by how much. It will then change the TA1CCR1 and TA1CCR2 values to increase power to the appropriate motor and make sure the robot is going straight. Ambitious, I know.

I will do this within a while loop which runs until the front sensor detects a wall. Again, using the compare function, the robot will turn accordingly. Time for some pseudocode!
