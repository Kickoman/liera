# how to use
Download full code, open .sln file in Visual Studio.

Default credentials for superadmin (to add new users):

> username: `superadmin`
>
> password: `superpassword`

Can be changed [here](https://github.com/bsuir-labs/liera/blob/a62076f95f5d8475f90b3424532fdf0cfc394148/source/InsuranceKeeper.cpp#L25)

# todo list
You can find it [here](https://github.com/bsuir-labs/liera/issues), add your propositions if needed.


## Known issues
* ~~`std::bad_alloc exception` on startup;~~
  ~~Possible fix: changing "Solution platform" to x86~~
* Can't find headers, e.g. `Appication.h` or `Layout.h`.
  Possible fix:
  
  Right-click on the project name in Solution Explorer, choose Properties, and drill down to Configuration Properties > C/C++ > General. The first field in the property sheet says "Additional Include Directories". Before you do anything else, click on the Configuration drop-down menu and choose All Configurations. If you have both a 32-bit and 64-bit build, click on the Platform drop-down menu and choose All Platforms. Now go to the "Additional Include Directories" and add all the paths:
  `..\..\..\source\console_app;..\..\..\source\data_managers;..\..\..\source;..\..\..\source\layouts`
