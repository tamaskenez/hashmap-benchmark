#ifndef INCLUDE_GUARD_util_1399971488
#define INCLUDE_GUARD_util_1399971488

#include <cstdint>

#include <string>
#include <sstream>

//randomize an integer with 64-bit FNV-1a hash
template<typename T>
T hash64(T x)
{
	const uint64_t offset_basis = 14695981039346656037ULL;
	const uint64_t FNV_prime = 1099511628211;

	uint64_t hash = offset_basis;
	for (int i = 0; i < sizeof(T); ++i)
	{
		hash ^= (x & 0xff);
		x >>= 8;
		hash *= FNV_prime;
	}
	return (T)hash;
}

//in-place replace searchString with replaceString
void replace_string(std::string& s, const std::string& searchString, const std::string& replaceString);

template<typename T>
std::string to_string(const T& x)
{
	std::ostringstream oss;
	oss << x;
	return oss.str();
}

std::string getcwd();

void save_result(const char* rel_fname, const char* data);

#endif

