#ifndef INCLUDE_GUARD_google_hash_map_adapters_1399903289
#define INCLUDE_GUARD_google_hash_map_adapters_1399903289

#include <limits>

#include <sparsehash/dense_hash_map>
#include <sparsehash/sparse_hash_map>
#include "config.h"

template<typename K, typename M>
class google_dense_hash_map_adapter
	: public google::dense_hash_map<K, M>
{
    typedef google::dense_hash_map<K, M> super_t;
public:
	google_dense_hash_map_adapter()
	{
		//needs to set special values, key must be signed
		static_assert(std::numeric_limits<K>::is_signed, "KEY_TYPE must be signed if you test google::dense_hash_map");
        super_t::set_empty_key(-1);
        super_t::set_deleted_key(-2);
	}
};

template<typename K, typename M>
class google_sparse_hash_map_adapter
	: public google::sparse_hash_map<K, M>
{
    typedef google::sparse_hash_map<K, M> super_t;
public:
	google_sparse_hash_map_adapter()
	{
		//needs to set special values, key must be signed
		static_assert(std::numeric_limits<K>::is_signed, "KEY_TYPE must be signed if you test google::sparse_hash_map");
        super_t::set_deleted_key(-2);
	}
};

#endif

