#pragma once

#include <cinttypes>
#include <cstddef>

namespace blowbox
{
  namespace core
  {
    class Memory;

    /**
    * @brief The base class for every allocator to inherit from
    *
    * This allocator does tracking of the memory size allocated and how much
    * open allocations there are. It will check for any memory leaks on shutdown
    * of the application. This however means that the application needs to be
    * shutdown properly.
    *
    * @see Memory
    *
    * @author Daniel Konings
    */
    class Allocator
    {

      friend class Memory;

    public:

      /**
      * @brief Construct the allocator with a maximum size
      *
      * @param[in] max_size The maximum size that can be allocated
      */
      Allocator(size_t max_size);

      /**
      * @brief Delete the copy constructor
      */
      Allocator(const Allocator& other) = delete;

      /**
      * @brief Delete the move operator
      */
      Allocator(const Allocator&& other) = delete;

      /**
      * @return The number of open allocations in this allocator
      */
      size_t open_allocations() const;

      /**
      * @return The amount of memory that is currently allocated
      */
      size_t allocated() const;

      /**
      * @brief Default destructor
      *
      * Checks for any leaks in the allocator
      */
      virtual ~Allocator();

    protected:

      /**
      * @brief Allocates a chunk of memory with a specified alignment
      *
      * This function calls the underlying implementation of the allocator that
      * derived from this Allocator base. (Allocator::AllocateImpl)
      * Calling allocations through these functions guarantee memory bookmarking.
      *
      * @param[in] size The size of the allocation
      * @param[in] align The alignment of the allocation
      *
      * @return A pointer to the address of the allocated memory
      */
      void* Allocate(size_t size, size_t align);

      /**
      * @brief Deallocates a previously allocated chunk of memory
      *
      * This function calls the underlying implementation of the allocator that
      * derived from this Allocator base. (Allocator::DeallocateImpl)
      * Calling allocations through these functions guarantee memory bookmarking.
      *
      * @param[in] ptr The pointer to the memory chunk to deallocate
      *
      * @return The size that was freed during the allocation
      */
      size_t Deallocate(void* ptr);

      /**
      * @see Allocator::Allocate
      */
      virtual void* AllocateImpl(size_t size, size_t align) = 0;

      /**
      * @see Allocator::Deallocate
      */
      virtual size_t DeallocateImpl(void* ptr) = 0;

    private:

      size_t max_size_; //!< The maximum size that can be allocated
      size_t open_allocations_; //!< The number of open allocations
      size_t allocated_; //!< The amount of memory that is currently allocated

    };
  }
}