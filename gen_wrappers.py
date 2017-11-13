import sys
f=open(sys.argv[1])

fout = open(sys.argv[2], "w")


#fout.write(".CODE\nEXTERN common_stub: PROC\n\n")
counter = 1
for i in f.read().strip().split("\n"):
	fout.write(i+" PROC EXPORT\n")
	fout.write("mov r11, " + str(counter) + "\n")
	fout.write("jmp common_stub\n")
	fout.write(i+ " ENDP\n")
	fout.write("\n")
	counter+=1


#fout.write("END\n")


fout.close()


fout=open(sys.argv[3], "w")

counter = 1

fout.write("void* function_pointers[] = {\n")
fout.write("\tNULL,\n")
f=open(sys.argv[1])
for i in f.read().strip().split("\n"):
	fout.write("\t(void*)"+i+", // "+ str(counter)+"\n")
fout.write("};\n")

