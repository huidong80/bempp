// Copyright (C) 2011-2012 by the BEM++ Authors
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

#ifndef bempp_abstract_boundary_operator_sum_hpp
#define bempp_abstract_boundary_operator_sum_hpp

#include "../common/common.hpp"

#include "abstract_boundary_operator.hpp"
#include "boundary_operator.hpp"

namespace Fiber
{

template <typename ResultType> class LocalAssemblerForOperators;

} // namespace Fiber

namespace Bempp
{

/** \brief Sum of linear operators.
 *
 *  \ingroup assembly
 */
template <typename BasisFunctionType_, typename ResultType_>
class AbstractBoundaryOperatorSum :
        public AbstractBoundaryOperator<BasisFunctionType_, ResultType_>
{
    typedef AbstractBoundaryOperator<BasisFunctionType_, ResultType_> Base;
public:
    /** \copydoc AbstractBoundaryOperator::BasisFunctionType */
    typedef typename Base::BasisFunctionType BasisFunctionType;
    /** \copydoc AbstractBoundaryOperator::ResultType */
    typedef typename Base::ResultType ResultType;
    /** \copydoc AbstractBoundaryOperator::CoordinateType */
    typedef typename Base::CoordinateType CoordinateType;
    /** \copydoc AbstractBoundaryOperator::QuadratureStrategy */
    typedef typename Base::QuadratureStrategy QuadratureStrategy;
    typedef typename Fiber::LocalAssemblerForOperators<ResultType>
    LocalAssembler;

    AbstractBoundaryOperatorSum(
            const BoundaryOperator<BasisFunctionType, ResultType>& term1,
            const BoundaryOperator<BasisFunctionType, ResultType>& term2);

    virtual bool supportsRepresentation(
            AssemblyOptions::Representation repr) const;

protected:
    virtual shared_ptr<DiscreteBoundaryOperator<ResultType_> >
    assembleWeakFormImpl(
            const Context<BasisFunctionType, ResultType>& context) const;

private:
    BoundaryOperator<BasisFunctionType, ResultType> m_term1, m_term2;
};

} //namespace Bempp

#endif