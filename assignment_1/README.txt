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
#update# I used random marble properties, 
so checking that the marble matches the one 
we inserted isnt going to work.

meeting criteria for assignment:

-lines 9, 31, 63-65 are used to generate the 
marbles properties and insert them into the bag.
This meets the criteria of marbles having properties.

-lines 17-59 show the implementation of all the different methods 
that can be performed on the bag.

-lines 67-71 are comments about the testing process.
Wasn't sure how to make a good automated test, so ran them manually.
tests were simple since program was very basic, might have overlooked something
due to manually testing everything.