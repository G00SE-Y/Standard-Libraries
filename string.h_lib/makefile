# variables
CC:= gcc

EXE_DIR := exe/
OUT_DIR := output/

MY_LIB_FILES := myString_Test.c myString.c 
MY_EXE_FILE  := my_string_lib_test

STD_LIB_FILES := stdString_Test.c
STD_EXE_FILE  := std_string_lib_test

MY_OUTPUT_FILE  := myString_Test_output.txt
STD_OUTPUT_FILE := stdString_Test_output.txt

RESULTS := string_test_results.txt

# compile my string test
my_string: $(MY_LIB_FILES)
	@$(CC) -Wall -Wextra -o $(EXE_DIR)$(MY_EXE_FILE) $(MY_LIB_FILES)

# compile std string test
std_string: $(STD_LIB_FILES)
	@$(CC) -Wall -Wextra -o $(EXE_DIR)$(STD_EXE_FILE) $(STD_LIB_FILES)

# create directories
make_dirs:
	@-mkdir exe
	@-mkdir output

# run files and compare output
build: make_dirs my_string std_string
	@echo "RUNNING STRING.H TESTS"
	@./$(EXE_DIR)$(STD_EXE_FILE)
	@./$(EXE_DIR)$(MY_EXE_FILE)
	@echo "CHECKING DIFF"
	@-diff $(OUT_DIR)$(STD_OUTPUT_FILE) $(OUT_DIR)$(MY_OUTPUT_FILE) > $(RESULTS)
	@echo "END OF STRING.H TESTS"
	@cat $(RESULTS)

# remove all created folders and files from building and testing
clean: 
	@rm -f -r output exe *.o *.exe *.txt all

rebuild: clean build