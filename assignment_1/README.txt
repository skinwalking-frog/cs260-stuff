marbles are represented as single digit integers 
to denote their relative size. The bag for storing 
marbles would be an array that can fit a total of 
only 10 marbles for simplicity. to add or remove 
marbles from the bag we can set that position
in the array to a 0 which would indicate no marble.
for organization and my OCD im going to make the marbles
bag get filled from the first element to the last and
emptied from last to first, basically a stack. 


to test the program we can add a marble to an empty bag, 
check the value of the marble is the same as the one 
we inserted, and remove it then check that the bag is 
emtpy.