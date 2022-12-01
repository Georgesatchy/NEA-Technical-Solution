from distutils.core import setup, Extension
import os

def main():
    setup(name="cipherTools",
          version="0.1",
          description="C++ based cipher tools module for Python",
          ext_modules=[Extension("cipherTools", sources=[os.path.relpath(os.path.join(path, name)) for path, subdirs, files in os.walk(os.getcwd()) for name in files if name.endswith(".cpp")] )])

if __name__ == "__main__":
    main()

# python setupModule.py install