import re
import string
import os


def allpurchases():
    # Opens the file
    document_text = open('CS210_Project_Three_Input_File.txt', 'r')
    # Creates a dictionary to store data
    freqs = dict()
    for line in document_text:
        # Removes spaces and breaks up lines into single words
        line = line.strip()
        words = line.split(" ")
        # Loop to add to frequency count
        for word in words:
            if word not in freqs:
                freqs[word] = 1
            else:
                freqs[word] += 1
    print("\n--------Items purchased today--------")
    # Prints the name and frequency for each product in the list
    for key in list(freqs.keys()):
        print(key, freqs[key])
    print("-------------------------------------\n")
    document_text.close()

def PrintMe(v):
    print("You sent me: " + v)
    return 100;

def SquareValue(v):
    return v * v

def ItemFreq(v):
    # Opens the file
    document_text = open('CS210_Project_Three_Input_File.txt', 'r')
    # Initializes the product frequency
    freq = 0
    # Capitalizes the first letter of user input for better accuracy
    v = v.capitalize()
    for line in document_text:
        line = line.strip()
        words = line.split(" ")
        for word in words:
            # Adds only the input product to the freq variable
            if word == v:
                freq += 1
    print("--------", v, " purchased today--------")
    # Shows the number of purchases for the selected item
    if freq > 0:
        print(v, " ", freq)
    # Displays a 0 for any entered items not on the list
    else :
        print(v + " 0")
    document_text.close()

def Histogram():
    document_text = open('CS210_Project_Three_Input_File.txt', 'r')
    # Creates the frequency.dat file if it doesn't exist, and opens it if it does exist
    new_doc = open("frequency.dat", "w")
    freqs = dict()
    # Same loop as the first function
    for line in document_text:
        line = line.strip()
        words = line.split(" ")
        for word in words:
            if word not in freqs:
                freqs[word] = 1
            else:
                freqs[word] += 1
    for key in list(freqs.keys()):
        # I put the items, a space, the frequency and a new line all in a tuple so I could
        # assign them all to one string further down
        key_tuple = (key, " ", (freqs[key]), "\n")
        # Assigns each string and integer above to a letter variable
        a, b, c, d = key_tuple
        # Coverts everything to strings and adds them to the variable 'a' so I could write to the file
        a += str(b)
        a += str(c)
        a += str(d)
        # Writes to the .dat file in a "Food frequency \n" format
        new_doc.write(a)
    document_text.close()
    new_doc.close()
