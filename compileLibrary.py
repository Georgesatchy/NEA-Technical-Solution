from distutils.core import setup, Extension
import os

# This function is used to compile all C++ code into a format such that it can be imported directly into a Python script as a library

def main():
    sources = [] # This list will contain relative paths of all .cpp files that need to be complied
    working_directory = os.getcwd() # Gets current working directory
    for path, subdirs, files in os.walk(working_directory): # Walks through the current working directory and its subfolders
        for name in files:
            if name.endswith(".cpp"): # Checks whether each given file is a C++ source file
                relative_path = os.path.relpath(os.path.join(path, name)) # Converts path and file name into a relative path
                sources.append(relative_path) # Appends these relative paths to the list of sources to compile

    setup(name="cipherTools",
          version="0.1",
          description="C++ based cipher tools library for Python",
          ext_modules=[Extension("cipherTools", sources=sources)]) # Creates a Python extension from the C++ source files in the CWD and subfolders

if __name__ == "__main__":
    main()

# Terminal command to compile into a library: python compileLibrary.py install