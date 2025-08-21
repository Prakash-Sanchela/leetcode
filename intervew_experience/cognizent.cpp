	1. Declare function pointer for int fun_name(int, int);
		1.  int fun_name(int, int);
		• Int (fptr*)(int,int);
	2. Now let's say fun_name() is a member function and if you want to declare function pointer. How do you do that?
		class A {
public:
 int f();
 int (A::*x)(); // <- declare by saying what class it is a pointer to
};
		int A::f() {
 return 1;
}
		int main() {
 A a;
 a.x = &A::f; // use the :: syntax
 printf("%d\n",(a.*(a.x))()); // use together with an object of its class
}
		
	3. In which case friend function is useful.
	4. Operator overloading for all the operator as a member function as well as friend function.
	5. Where the memory is getting allocated for vector? Have you used std::set
	6. What is the difference between iterator and simple pointer?
	7. Define the vector of pointer to that class and find out which is the same object pointer by any pointer.
	8. Declare a vector of any class and invoke it's constructor while declared time of the vector only. In short define and declare a vector of any class and initialize it.
		class A{
		public:
		    A() {
		        cout << " In Class A " << endl;
		    }
		};
		int main(){ 
		  vector<A*> vec = {new A(), new A()};
		}
		
	9. What happened when we do CoInitialize() for COM?
	10. If the COM vendor changes something in COM library, what should be your steps to use the updated COM dll?
	11. Functors? And what is it's use?
	12. Have you used any database?
	13. Compilation steps
	14. WAP to print the name before main and after main.
		a. Before main
		b. In Main 
		c. After Main
	
	
	
