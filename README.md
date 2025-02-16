# CalculateFloatSkins
A tool to calculate the float of a CS2 skin on trade ups.

The way it works is by inputing one or join multiple arrays into one, with all skin floats.
There is also a variable to cap the maximum float.
Then the program will calculate the combination of the 10 skins with the highest average float bellow the max float that you chose.
As the program will start to print the skins on the console, it will search the skins and color them in groups.
It will also print the combination to combination.txt and all the log to combination_log.txt

How you can set it up:
1. Declare one or more arrays with the names of the skins that you want to put in the trade up. (one array per skin and all of them as global variables)
2. Input the floats of every skin on the respective arrays.
3. Go to the "std::string getSkinName(double skinFloat, int num)" function and add your skins to the switch so it can print on the console with colors. (It wont work without it)
4. If you have multiple arrays, you have to join them together on main function.
   Example: dangerZone.insert(dangerZone.end(), MAC10PipeDowns.begin(), MAC10PipeDowns.end());
   Here I joined MAC10PipeDowns array to dangerZone array.
5. Lastly call the void processCombination(const std::vector<double> &values, double target, int mode) function on main.
   &values - the array with all floats
   target - max value that you want.
   mode - the number that you input on the switch