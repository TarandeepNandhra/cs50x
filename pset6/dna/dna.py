from sys import argv, exit
import csv

if len(argv) != 3:
    print("python dna.py CSVfile DNAseq")
    exit(1)

with open(argv[2]) as DNAfile:
    DNAreader = csv.reader(DNAfile)
    for row in DNAreader:
        DNAlist = row

#DNA in a string
DNA = row[0]

#create a dictionary
sequences = {}

#obtains a list containing all gene types
with open(argv[1]) as peoplefile:
    people = csv.reader(peoplefile)
    for row in people:
        #puts first row in a list
        DNASequences = row
        #.pop(i) removes ith element in list so remove 0th ele which is "name"
        DNASequences.pop(0)
        #DNASequences is a list of all gene types
        break

    #each gene (item) becomes a key of the dictionary with value = 1
    for item in DNASequences:
        sequences[item] = 1


for key in sequences:
    l = len(key)
    tempMax = 0
    temp = 0
    for i in range(len(DNA)):
        while temp > 0:
            temp -= 1
            continue
        if DNA[i: i + l] == key:
            while DNA[i - l: i] == DNA[i: i + l]:
                temp += 1
                i += l
                #increases i by 4 to move to next 4
            if temp > tempMax:
                tempMax = temp

    sequences[key] += tempMax

with open(argv[1], newline='') as peoplefile:
    people = csv.DictReader(peoplefile)
    #each row starts with person and then number for each gene
    for person in people:
        match = 0
        for DNA in sequences:
            #here DNA is each GENE as looking at keys in sequences
            if sequences[DNA] == int(person[DNA]):
                match += 1
        #number of matches, must be the total number of genes for a match
        if match == len(sequences):
            #prints their name as 'name' is the key in the dictionary
            #and 'name' has value 'persons actual name'
            print(person['name'])
            exit()
    print("No match")