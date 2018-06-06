//////////////////////////////////////////////////////////////////////////
//  @file     unique_ptr.h
//  @author   VincentLee
//  @date     2018-05-28
//  @mail     vincentleecn@163.com
//
//  @version  2018-05-28
//  -added    first record
//  @remark   
//  @note
//////////////////////////////////////////////////////////////////////////


#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <iostream>
#include <memory> // for std::unique_ptr

namespace cm_unique
{
	class Resource
	{
	public:
		Resource() { std::cout << "Resource acquired\n"; }
		~Resource() { std::cout << "Resource destroyed\n"; }
		friend std::ostream& operator<<(std::ostream& out, const Resource &res)
		{
			out << "I am a resource\n";
			return out;
		}
	};

	int sampluse()
	{
		// allocate a Resource object and have it owned by std::unique_ptr
		std::unique_ptr<Resource> res(new Resource);
		
		return 0;
	} // res goes out of scope here, and the allocated Resource is destroyed

	int move()
	{
		std::unique_ptr<Resource> res1(new Resource); // Resource created here
		std::unique_ptr<Resource> res2; // Start as nullptr

		std::cout << "res1 is " << (static_cast<bool>(res1) ? "not null\n" : "null\n");
		std::cout << "res2 is " << (static_cast<bool>(res2) ? "not null\n" : "null\n");

		// res2 = res1; // Won't compile: copy assignment is disabled
		res2 = std::move(res1); // res2 assumes ownership, res1 is set to null

		std::cout << "Ownership transferred\n";

		std::cout << "res1 is " << (static_cast<bool>(res1) ? "not null\n" : "null\n");
		std::cout << "res2 is " << (static_cast<bool>(res2) ? "not null\n" : "null\n");

		return 0;
	} // Resource destroyed here when res2 goes out of scope


	/*
	std::unique_ptr has an overloaded operator* and operator-> that can be 
	used to return the resource being managed. Operator* returns a reference 
	to the managed resource, and operator-> returns a pointer.

	Remember that std::unique_ptr may not always be managing an object -- 
	either because it was created empty (using the default constructor or
	passing in a nullptr as the parameter), or because the resource it was 
	managing got moved to another std::unique_ptr. So before we use either of 
	these operators, we should check whether the std::unique_ptr actually has
	a resource. Fortunately, this is easy: std::unique_ptr has a cast to bool
	that returns true if the std::unique_ptr is managing a resource.
	*/
	
	int check()
	{
		std::unique_ptr<Resource> res(new Resource);

		if (res) // use implicit cast to bool to ensure res contains a Resource
			std::cout << *res; // print the Resource that res is owning

		return 0;
	}

	void takeOwnership(std::unique_ptr<Resource> res)
	{
		if (res)
			std::cout << *res;
	} // the Resource is destroyed here

	int Ownership()
	{
		//auto ptr = std::make_unique<Resource>();
		std::unique_ptr<Resource> ptr(new Resource);
		// takeOwnership(ptr); // This doesn't work, need to use move semantics
		takeOwnership(std::move(ptr)); // ok: use move semantics

		std::cout << "Ending program\n";

		return 0;
	}


	//Note that in this case, ownership of the Resource was transferred to 
	//takeOwnership(), so the Resource was destroyed at the end of
	//takeOwnership() rather than the end of main().
	//However, most of the time, you won¡¯t want the function to take ownership of
	//the resource. Although you can pass a std::unique_ptr by reference
	//(which will allow the function to use the object without assuming ownership),
	//you should only do so when the caller might alter or change the object being 
	//managed.Instead, it¡¯s better to just pass the resource itself (by pointer 
	//or reference, depending on whether null is a valid argument). This allows
	//the function to remain agnostic of how the caller is managing its resources.
	//To get a raw resource pointer from a std::unique_ptr, you can use the get()
	//member function:



	// The function only uses the resource, so we'll accept a pointer to the
	// resource, not a reference to the whole std::unique_ptr<Resource>
	void useResource(Resource *res)
	{
		if (res)
			std::cout << *res;
	}

	int get()
	{
		// C++ 14
		//auto ptr = std::make_unique<Resource>();
		std::unique_ptr<Resource> ptr(new Resource);

		useResource(ptr.get()); // note: get() used here to get a pointer to the Resource

		std::cout << "Ending program\n";

		return 0;
	} // The Resource is destroyed here

}



#endif // UNIQUE_PTR_H