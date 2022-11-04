from distutils.core import setup, Extension

def main():
    setup(name="cipherTools",
          description="C++ based cipher tools module for Python",
          ext_modules=[Extension("cipherTools", ["cipherTools.cpp"])])

if __name__ == "__main__":
    main()

# python setupModule.py install