from distutils.core import setup, Extension

def main():
    setup(name="cipherTools",
          version="0.1",
          description="C++ based cipher tools module for Python",
          ext_modules=[Extension("cipherTools", sources=["cipherTools.cpp", "caesar.cpp", "analyse.cpp"])])

if __name__ == "__main__":
    main()

# python setupModule.py install