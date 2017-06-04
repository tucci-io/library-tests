///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 - 2011 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2011-01-15
// Updated : 2011-09-13
// Licence : This source is under MIT licence
// File    : test/core/func_packing.cpp
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <glm/glm.hpp>
#include <glm/gtc/half_float.hpp>
#include <glm/gtc/type_precision.hpp>
#include <glm/gtx/epsilon.hpp>
#include <vector>

int test_packUnorm2x16()
{
	int Error = 0;
/*	
	std::vector<glm::hvec2> A;
	A.push_back(glm::hvec2(glm::half( 1.0f), glm::half( 0.0f)));
	A.push_back(glm::hvec2(glm::half( 0.5f), glm::half( 0.7f)));
	A.push_back(glm::hvec2(glm::half( 0.1f), glm::half( 0.2f)));
*/
	std::vector<glm::vec2> A;
	A.push_back(glm::vec2(1.0f, 0.0f));
	A.push_back(glm::vec2(0.5f, 0.7f));
	A.push_back(glm::vec2(0.1f, 0.2f));

	for(std::size_t i = 0; i < A.size(); ++i)
	{
		glm::vec2 B(A[i]);
		glm::uint32 C = glm::packUnorm2x16(B);
		glm::vec2 D = glm::unpackUnorm2x16(C);
		Error += glm::all(glm::equalEpsilon(B, D, 1.0f / 65535.f)) ? 0 : 1;
		assert(!Error);
	}
	
	return Error;
}

int test_packSnorm2x16()
{
	int Error = 0;
/*
	std::vector<glm::hvec2> A;
	A.push_back(glm::hvec2(glm::half( 1.0f), glm::half( 0.0f)));
	A.push_back(glm::hvec2(glm::half(-0.5f), glm::half(-0.7f)));
	A.push_back(glm::hvec2(glm::half(-0.1f), glm::half( 0.1f)));
*/
	std::vector<glm::vec2> A;
	A.push_back(glm::vec2( 1.0f, 0.0f));
	A.push_back(glm::vec2(-0.5f,-0.7f));
	A.push_back(glm::vec2(-0.1f, 0.1f));

	for(std::size_t i = 0; i < A.size(); ++i)
	{
		glm::vec2 B(A[i]);
		glm::uint32 C = glm::packSnorm2x16(B);
		glm::vec2 D = glm::unpackSnorm2x16(C);
		Error += glm::all(glm::equalEpsilon(B, D, 1.0f / 32767.0f * 2.0f)) ? 0 : 1;
		assert(!Error);
	}
	
	return Error;
}

int test_packUnorm4x8()
{
	int Error = 0;
	
	std::vector<glm::vec4> A;
	A.push_back(glm::vec4(1.0f, 0.7f, 0.3f, 0.0f));
	A.push_back(glm::vec4(0.5f, 0.1f, 0.2f, 0.3f));
	
	for(std::size_t i = 0; i < A.size(); ++i)
	{
		glm::vec4 B(A[i]);
		glm::uint32 C = glm::packUnorm4x8(B);
		glm::vec4 D = glm::unpackUnorm4x8(C);
		Error += glm::all(glm::equalEpsilon(B, D, 1.0f / 255.f)) ? 0 : 1;
		assert(!Error);
	}
	
	return Error;
}

int test_packSnorm4x8()
{
	int Error = 0;
	
	std::vector<glm::vec4> A;
	A.push_back(glm::vec4( 1.0f, 0.0f,-0.5f,-1.0f));
	A.push_back(glm::vec4(-0.7f,-0.1f, 0.1f, 0.7f));
	
	for(std::size_t i = 0; i < A.size(); ++i)
	{
		glm::vec4 B(A[i]);
		glm::uint32 C = glm::packSnorm4x8(B);
		glm::vec4 D = glm::unpackSnorm4x8(C);
		Error += glm::all(glm::equalEpsilon(B, D, 1.0f / 127.f)) ? 0 : 1;
		assert(!Error);
	}
	
	return Error;
}

int test_packHalf2x16()
{
	int Error = 0;
/*
	std::vector<glm::hvec2> A;
	A.push_back(glm::hvec2(glm::half( 1.0f), glm::half( 2.0f)));
	A.push_back(glm::hvec2(glm::half(-1.0f), glm::half(-2.0f)));
	A.push_back(glm::hvec2(glm::half(-1.1f), glm::half( 1.1f)));
*/
	std::vector<glm::vec2> A;
	A.push_back(glm::vec2( 1.0f, 2.0f));
	A.push_back(glm::vec2(-1.0f,-2.0f));
	A.push_back(glm::vec2(-1.1f, 1.1f));

	for(std::size_t i = 0; i < A.size(); ++i)
	{
		glm::vec2 B(A[i]);
		glm::uint C = glm::packHalf2x16(B);
		glm::vec2 D = glm::unpackHalf2x16(C);
		//Error += B == D ? 0 : 1;
		Error += glm::all(glm::equalEpsilon(B, D, 1.0f / 127.f)) ? 0 : 1;
		assert(!Error);
	}
	
	return Error;
}

int test_packDouble2x32()
{
	int Error = 0;
	
	std::vector<glm::u32vec2> A;
	A.push_back(glm::u32vec2( 1, 2));
	A.push_back(glm::u32vec2(-1,-2));
	A.push_back(glm::u32vec2(-1000, 1100));
	
	for(std::size_t i = 0; i < A.size(); ++i)
	{
		glm::u32vec2 B(A[i]);
		double C = glm::packDouble2x32(B);
		glm::u32vec2 D = glm::unpackDouble2x32(C);
		Error += B == D ? 0 : 1;
		assert(!Error);
	}
	
	return Error;
}

int main()
{
	int Error = 0;
	
	Error += test_packSnorm4x8();
	Error += test_packUnorm4x8();
	Error += test_packSnorm2x16();
	Error += test_packUnorm2x16();
	Error += test_packHalf2x16();
	Error += test_packDouble2x32();

	return Error;
}

