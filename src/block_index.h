// Copyright (c) 2014-2020 The Gridcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <array>
#include <forward_list>

class CBlockIndex;

namespace MAGI {

//!
//! \brief Bulk-allocates block index objects to improve heap efficiency.
//!
//! Because of the relatively small block spacing, the block index eclipses
//! the memory usage of every other component in Magicoin by a wide margin.
//! This object pool reduces the administrative overhead needed to allocate
//! objects from the heap when compared to one-off allocations for millions
//! of instances. Retrieve new entries from this pool instead of allocating
//! them with the \c new operator.
//!
//! The pool does not provide a way to return discarded objects because the
//! application never removes or destroys block index entries.
//!
//! TODO: Consider a specialized hash table implementation for the block index
//! map with more efficient memory management than \c std::unordered_map. This
//! pool serves as a crutch until we can address the scalability problems with
//! the block index on a deeper level.
//!
class BlockIndexPool
{
public:
    //!
    //! \brief Get the next available block index instance from the pool.
    //!
    static CBlockIndex* GetNextBlockIndex()
    {
        return m_block_index_pool.GetNext();
    }
    static void DeleteMBlock()
    {
        m_block_index_pool.DeleteMBlock();
    }
//     static Pool<CBlockIndex> GetMBlock()
//     {
//         return m_block_index_pool;
//     }
//     void DeleteMBlock()
//     {
//         m_block_index_pool.DeleteMBlock();
//     }


private:
    //!
    //! \brief Allocates objects in chunks and provides access to unclaimed
    //! instances.
    //!
    template <typename T>
    class Pool
    {
        //!
        //! \brief Number of objects to allocate per chunk.
        //!
        //! For block index objects, this results in about a 5 MB allocation
        //! per chunk.
        //!
        static constexpr size_t CHUNK_SIZE = 32768;

    public:
        //!
        //! \brief Initialize a new pool.
        //!
        Pool() : m_pool(1), m_offset(0)
        {
        }

        //!
        //! \brief Get the next available instance from the pool.
        //!
        T* GetNext()
        {
            if (m_offset >= CHUNK_SIZE) {
                m_pool.emplace_front();
                m_offset = 0;
            }

            return &m_pool.front()[m_offset++];
        }
        void DeleteMBlock()
        {
            m_pool.clear();
        }

    private:
        //!
        //! \brief The collection of allocated chunks in the pool.
        //!
        //! Each element holds a batch of \p T objects, and the front entry
        //! in the list contains the unclaimed objects in the pool when the
        //! item offsets follow the offset stored in the \c m_offset field.
        //!
        //! For the sake of avoiding a memory leak, we use a linked list to
        //! manage the allocated chunks. We could allocate the arrays using
        //! the \c new operator directly like before, and the OS will clean
        //! up the leak when the program exits. Since the overhead for this
        //! wrapper list is negligible, we favor the explicit management of
        //! memory in case we need to reset the pool in the future.
        //!
        std::forward_list<std::array<T, CHUNK_SIZE>> m_pool;

        //!
        //! \brief The offset of the next available instance in the current
        //! chunk of unclaimed pool objects.
        //!
        //! The value advances when claiming an object from the pool and it
        //! resets to zero when allocating a new chunk.
        //!
        size_t m_offset;
    };

    static Pool<CBlockIndex> m_block_index_pool;

}; // BlockIndexPool
} // namespace MAGI
