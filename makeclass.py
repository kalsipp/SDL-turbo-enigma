import sys
import os.path
if(len(sys.argv) == 2):
	if(sys.argv[1][0].isupper()):
		sys.exit("Error, name must be lowercase")
	print "Making " + sys.argv[1] + ".hpp and " + sys.argv[1] + ".cpp."
	filenamehpp = "src/" + sys.argv[1] + ".hpp"
	filenamecpp = "src/" + sys.argv[1] + ".cpp"
	if(os.path.isfile(filenamehpp)):
		print filenamehpp +" already exists. Aborting."
	elif(os.path.isfile(filenamecpp)):
		print filenamecpp +" already exists. Aborting."
	else:
		print "No files found. Creating files."
		file = open(filenamehpp, "w+")
		file.write("#pragma once\n")
		file.write("\n")
		file.write("class " + sys.argv[1].title() + "{\n")
		file.write("public:\n")
		file.write("\n")
		file.write("private:\n")
		file.write("\n")
		file.write("};")
		file.close()

		file = open(filenamecpp, "w+")
		file.write("#include \"" + sys.argv[1] + ".hpp\"")
		file.close
else:
	print "Please enter one filename."
