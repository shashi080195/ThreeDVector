# ThreeDVector

The Following program is used to perform mathematical operations between 3D vectors.
Single Level inheritance is used as design principle

There are two classes 
* ThreeDVector
	-> this class holds coordinate of a vector such as  x , y and z co-ordinate 
	-> It also contains abstract method which must be overriden while inheriting this class
* Vector
	-> this class inherits the ThreeDVcetor class and provides mathematical operations
	   functionality which can be performed on two vectors.
	-> this class also has overloaded arithemtic operator which are used to perform basic arithmetic 
	   operations such as "+","-","*".