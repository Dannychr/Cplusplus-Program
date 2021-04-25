# Cplusplus-Program

# Summarize the project and what problem it was solving
  This project uses a combination of C++ and Python to read a list of grocery items and reorganize the list in a few different ways according to user input. It simplifies the list by removing duplicate items and instead shows a number by the item for the number of occurences in the list. It then allows the user to display the whole simplified list, displaying only a single item, or display a text-based histogram using asterisks as tallies.
  
# What did you do particularly well?
  I think I did a good job of preventing any program errors due to user mistake. For example, if the user enters a letter instead of a number in the initial menu, I added a few lines to stop the endless loop, output a message explaining the mistake, and take the user back to the menu. For the second option in the program, I added a link to automatically capitalize the first letter of the user's input to prevent potential typos. For example, if the user typed "peas", the program wouldn't pull any of the 8 occurences of "Peas" from the list, so now the program automatically changed "peas" to "Peas" before searching. I also added a section to handle entries that aren't on the list, so if the user enters something like "Bamboo", the program will output "Bamboo: 0" instead of not triggering any output.
