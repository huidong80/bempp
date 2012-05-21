#ifndef fiber_shared_ptr_hpp
#define fiber_shared_ptr_hpp

#include <boost/shared_ptr.hpp>

namespace Fiber
{

using boost::shared_ptr;

struct null_deleter
{
    void operator() (const void*) const {
    }
};

/** \brief Create a shared pointer from a reference to an object allocated on stack.

The object will not be deleted when the shared pointer goes out of scope. */
template <typename T>
inline shared_ptr<T> make_shared_from_ref(T& t)
{
    return shared_ptr<T>(&t, null_deleter());
}

} // namespace Fiber

#endif // fiber_shared_ptr_hpp