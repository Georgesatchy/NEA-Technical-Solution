from distutils.core import setup, Extension
import os

def main():
    setup(name="cipherTools",
          version="0.1",
          description="C++ based cipher tools module for Python",
          ext_modules=[Extension("cipherTools", sources=[file for file in os.listdir(os.getcwd()) if file.endswith(".cpp")])])

if __name__ == "__main__":
    main()

# python setupModule.py install