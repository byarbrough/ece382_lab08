ece382_lab08
============

[Lab 8 - Robot Maze](http://ece382.com/labs/lab8/index.html)

##Prelab
I am going to be ambitious here: my robot will be able to solve any path maze. By that, I meand that I am not going to hard code "left turn first, then right turn, ect." Instead, I am going to make a robot that goes straight until it sees a wall and then makes an educated decision on turning. Furthermore, it will do this with using the IR sensors (and the nice library I made!) and will do it quickly. I am pretty excited about this.

To start with, I will need a battle plan. Now, one of the key requirements is not hitting a wall. Stopping when a wall is straigth ahead is easy; the more difficult part is to avoid drifting into a wall instead of going straight. To avoid this, I am going to modify my library to have a function that returns which sensor - left or right - is closest to the wall, and by how much. It will then change the TA1CCR1 and TA1CCR2 values to increase power to the appropriate motor and make sure the robot is going straight. Ambitious, I know.

I will do this within a while loop which runs until the front sensor detects a wall. Again, using the compare function, the robot will turn accordingly. Time for some pseudocode!

##The Lab
I quickly figured out that things were not going to go smoothly. This was coupled with mutlipe errors, some of them my fault, othes not.

First, and this took me hours to figure out, my robot was just plain broken. The front IR sensor didn't work, even though it did for Lab 07. When I went and reloaded Lab 07, the sensor still did not work. I was attempting to try and do the maze with only side sensors when C2C Arneberg was kind enough to let me use his robot. Becuase they were wired simmilarly, it shouldn't have been a problem.

Note, I said similar, not the same. I was still having issues with the fron sensor. Hooking of the DDM showed that the line was always pulled to 3.3 V. Curious. It turns out that I still had a leftover line of pullup resistor code - from the buttons - on P1.3 that I didn't notice before because of the different wiring schematics.

I did get requuired functionality, but then I got the .out file error which noone knows how to fix before I could run B.

Here is that video.
<iframe width="854" height="510" src="//www.youtube.com/embed/OpqCALrZezk?list=UUhaeaBbbFdB9VKMV7lU9E9g" frameborder="0" allowfullscreen></iframe>

https://www.youtube.com/watch?v=OpqCALrZezk&list=UUhaeaBbbFdB9VKMV7lU9E9g 

All in all, I learned a lot from this couse. I am dissapointed that this lab was so difficult because of hardware errors, and that I could not get additional points for B and A funct because of Code Composer Studio errors. This may ultimately get me a lower grade in the couse than I deserve; I got A functionality on every single lab other than this one.

I also used some of Jasper's code to troubleshoot, but the maze was my own.
