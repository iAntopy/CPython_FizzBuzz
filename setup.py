from distutils.core import setup, Extension

myModule = Extension("cFizzBuzz", sources = ["cFizzBuzz.c"])

setup(name = "cFizzBuzz",
	version = "0.0.1",
	description = "A FizzBuzz module in C",
	ext_modules = [myModule]	
)
