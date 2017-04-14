// this function is completely legitimate
int* pointer_to_static(){
    
/*
    By saying that x is static, we are saying that we want to allocate it once, and only once, at
    some point before the first time that pointer_to_static is ever called, and that we do not want
    to deallocate it as long as our program runs. There is nothing wrong with returning the
    address of a static variable; the pointer will be valid as long as the program runs, and it will be
    irrelevant afterward.  However, the disadvantage is that this function will return a pointer to the same object everytime.
*/
    
    static int x; 
    return &x; // address of variable
}