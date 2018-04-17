#include "allocator.h"

namespace blowbox
{
  namespace core
  {
    //------------------------------------------------------------------------------------------------------
    Allocator::Allocator(size_t max_size) :
      max_size_(max_size),
      open_allocations_(0),
      allocated_(0)
    {

    }

    //------------------------------------------------------------------------------------------------------
    size_t Allocator::open_allocations() const
    {
      return open_allocations_;
    }

    //------------------------------------------------------------------------------------------------------
    size_t Allocator::allocated() const
    {
      return allocated_;
    }

    //------------------------------------------------------------------------------------------------------
    Allocator::~Allocator()
    {
      //assert(open_allocations_ == 0 && allocated_ == 0 && "Memory leak detected in an allocator");
    }

    //------------------------------------------------------------------------------------------------------
    void* Allocator::Allocate(size_t size, size_t align)
    {
      if (allocated_ + size > max_size_)
      {
        //Logger::Assert(false, "Buffer overflow in allocator");
        return nullptr;
      }

      allocated_ += size;
      ++open_allocations_;

      return AllocateImpl(size, align);
    }

    //------------------------------------------------------------------------------------------------------
    size_t Allocator::Deallocate(void* ptr)
    {
      size_t deallocated = DeallocateImpl(ptr);

      if (max_size_ < deallocated)
      {
        //Logger::Assert(false, "Attempted to deallocate more than was ever allocated");
        return 0;
      }

      allocated_ -= deallocated;
      --open_allocations_;

      return deallocated;
    }
  }
}