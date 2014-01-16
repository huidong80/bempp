// Copyright (C) 2011-2014 by the BEM++ Authors
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "helmholtz_3d_osrc_dtn_operator.hpp"
#include "abstract_boundary_operator.hpp"
#include "../fiber/scalar_traits.hpp"
#include "laplace_beltrami_3d_operator.hpp"

namespace Bempp {

namespace {


template <typename BasisFunctionType_>
class Helmholtz3dOsrcDtnOperator :
        public AbstractBoundaryOperator<BasisFunctionType_,typename Fiber::ScalarTraits<BasisFunctionType_>::ComplexType>
{

public:

    typedef AbstractBoundaryOperator<BasisFunctionType_,typename Fiber::ScalarTraits<BasisFunctionType_>::ComplexType> Base;
    typedef Base::BasisFunctionType BasisFunctionType;
    typedef Base::ResultType ResultType;
    typedef Base::CoordinateType CoordinateType;

    Helmholtz3dOsrcDtnOperator(
            const shared_ptr<const Space<BasisFunctionType> >& domain,
            const shared_ptr<const Space<BasisFunctionType> >& range,
            const shared_ptr<const Space<BasisFunctionType> >& dualToRange,
            int numberOfPadeTerms,
            const std::string& label,
            int symmetry) :
        Base(domain,range,dualToRange,label,symmetry),
        m_numberOfPadeTerms(numberOfPadeTerms)
    {}

    virtual bool isLocal() const {
        return true;
    }

protected:

    virtual shared_ptr<DiscreteBoundaryOperator<ResultType> >
    assembleWeakFormImpl(const Context<BasisFunctionType, ResultType> &context) const {




    }



private:

    int m_numberOfPadeTerms;


};


}



template <typename BasisFunctionType, typename ResultType>
BoundaryOperator<BasisFunctionType, ResultType>
helmholtz3dOsrcDtnOperator(
        const shared_ptr<const Context<BasisFunctionType, ResultType> >& context,
        const shared_ptr<const Space<BasisFunctionType> >& domain,
        const shared_ptr<const Space<BasisFunctionType> >& range,
        const shared_ptr<const Space<BasisFunctionType> >& dualToRange,
        const std::string& label,
        int symmetry) {}



}
