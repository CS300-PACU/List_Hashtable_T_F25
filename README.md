## C++ in VS Code in a Linux Dev Container

### Code Formatting
Apply the coding standards via:
* Windows: ```SHIFT + ALT + F```
* Mac: ```SHIFT + OPTION + F```
* Linux: ```CTRL + SHIFT + I```

## How to toggle between List and Hashtable unit tests in VS Code:
* Open the Command Palette (F1 or Gear Icon | Comman Palette)
* CMake: Set Launch/Debug target
* Choose the correct target
* Use the run or debug icon at the bottom of VS Code.

### Alternative Method
* Open the TESTING (flask icon) extension
* Drop down TestMake C++
* Drop down TestsToRun_HT or TestsToRun_List
* Hover over the individual test to run/debug and use the arrow or bug&arrow icon

## Testing on Zeus

### List
```
 cd List/

 # install google test

 cd ..

 List/buildUnitTests.sh

 build/List/test/TestsToRun_List

 make valgrindUnittests
```
### Hashtable
```
 cd Hashtable/

 # install google test

 cd ..

 Hashtable/buildUnitTests.sh

 build/Hashtable/test/TestsToRun_HT

 make valgrindUnittests

 make 
 
 bin/htInvoiceDriver
 
 make valgrindHtInvoideDriver
``` 

## Create and run GoogleTest

* We will standardize on a particular version of Google Test this semester:
```
wget https://github.com/google/googletest/archive/refs/tags/v1.15.2.tar.gz;
tar zxf v1.15.2.tar.gz;
mv googletest-1.15.2/ googletest;
rm v1.15.2.tar.gz;
```

* In the lower left of the Explorer window you will see Codespaces: and the name of your running codespace which is two words. At the far right you will see a triangle pointing right. Click that icon.
* You will be asked to select a Kit. Set the Kit to **Unspecified**. This only needs to be done once.
* Run unit tests from the command line:
   * At the command line:
   ```
   export CXX=`which clang++-16`;
   echo $CXX;
   cmake -S . -B ./build;
   cmake --build build --target clean;
   cmake --build build;
   ```
   * If you want to enable the debugger for the unit tests use:
   ```
   export CXX=`which clang++-16 -fstandalone-debug -g`
   ```
   * To run the test cases:
   ```
   build/test/TestsToRun_List
	 or
	 build/test/TestsToRun_HT
	 
   ```

## Notes
* [GDB to LLDB Command Mapping](https://lldb.llvm.org/use/map.html)
* [Using expressions in the watch panel with LLDB](https://github.com/vadimcn/vscode-lldb/blob/master/MANUAL.md#native-expressions)
* To view the data pointed to by a void* 
  *   For LLDB: 
	  * `/nat *(int*) pVoid`
* [View pointer as array in debugger](https://github.com/microsoft/vscode-cpptools/issues/172#issuecomment-1281804128)
  *   For LLDB:
	  * `/nat *(int(*)[13])pIntArray`
  *   For GDB:
      * `*pIntArray@13` or  `*pIntArray@ARRAY_SIZE`
