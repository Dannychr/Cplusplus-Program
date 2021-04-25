# Cplusplus-Program

# Summarize the project and what problem it was solving
  This project uses a combination of C++ and Python to read a list of grocery items and reorganize the list in a few different ways according to user input. It simplifies the list by removing duplicate items and instead shows a number by the item for the number of occurences in the list. It then allows the user to display the whole simplified list, displaying only a single item, or display a text-based histogram using asterisks as tallies.
  
# What did you do particularly well?
  I think I did a good job of preventing any program errors due to user mistake. For example, if the user enters a letter instead of a number in the initial menu, I added a few lines to stop the endless loop, output a message explaining the mistake, and take the user back to the menu. For the second option in the program, I added a link to automatically capitalize the first letter of the user's input to prevent potential typos. For example, if the user typed "peas", the program wouldn't pull any of the 8 occurences of "Peas" from the list, so now the program automatically changed "peas" to "Peas" before searching. I also added a section to handle entries that aren't on the list, so if the user enters something like "Bamboo", the program will output "Bamboo: 0" instead of not triggering any output.

# Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
  I don't think the way I handled writing to the frequency.dat file was done particularly well, but I wasn't able to find another way to do it. It seems kind of silly and inefficient to add string variables to a tuple, then assign them to new variables and convert the new variables to strings just to concatenate them to another string, and then finally write to a file. There has to be a better way.
  
# Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
  Apart from the bit of code I mentioned in the previous answer, I also hit a bit of a wall when it came to writing code in C++ to read and assign data from the frequency.dat file to variables. I ended up finding an explanation deep in a forum and after the data was assigned, the rest was simple. While online guides and tutorials are very helpful, I think human discussion is the most helpful way to get information. Stack Overflow's forums have tons of posts from people working on projects not even close to similar to mine, but I'm still able to find bits of information and explanations in them.
  
# What skills from this project will be particularly transferable to other projects or course work?
  Without a doubt, the most helpful skill from this project is accessing and transferring data between files. Even if it's a single-language project, keeping different parts of the program in separate files is a great way to keep the program clean and organized. I'm sure on larger projects, this will be essential for processing speed as well.
 
# How did you make this program maintainable, readable, and adaptable?
  While writing the code for this project, I tried to use naming conventions that made sense without being too large. For example, I could have named the variable for grocery items "x", but ten minutes laters I probably wouldn't remember what "x" contained. I also used in-line comments to not only explain the code, but to break up blocks and make them easier to read.
