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

#ifndef bempp_helmholtz_3d_hypersingularoperator_hpp
#define bempp_helmholtz_3d_hypersingularoperator_hpp

#include "helmholtz_3d_operator_base.hpp"

#include <boost/scoped_ptr.hpp>

namespace Bempp
{

template <typename BasisFunctionType>
struct Helmholtz3dHypersingularOperatorImpl;

/** \ingroup helmholtz_3d
 *  \brief Hypersingular operator for the Helmholtz equation in 3D.
 *
 *  \tparam BasisFunctionType
 *    Type used to represent the values of basis functions. It can take the
 *    following values: \c float, \c double, <tt>std::complex<float></tt> and
 *    <tt>std::complex<double></tt>.
 *
 *  \see helmholtz_3d */
template <typename BasisFunctionType_>
class Helmholtz3dHypersingularOperator :
        public Helmholtz3dOperatorBase<
                Helmholtz3dHypersingularOperatorImpl<BasisFunctionType_>,
                BasisFunctionType_>
{
    typedef Helmholtz3dOperatorBase<
    Helmholtz3dHypersingularOperatorImpl<BasisFunctionType_>,
    BasisFunctionType_> Base;
public:
    typedef typename Base::BasisFunctionType BasisFunctionType;
    typedef typename Base::KernelType KernelType;
    typedef typename Base::ResultType ResultType;
    typedef typename Base::CoordinateType CoordinateType;
    typedef typename Base::CollectionOfBasisTransformations
    CollectionOfBasisTransformations;
    typedef typename Base::CollectionOfKernels CollectionOfKernels;
    typedef typename Base::TestKernelTrialIntegral TestKernelTrialIntegral;

    /** \brief Construct the operator.
     *
     * \param testSpace Test function space.
     * \param trialSpace Trial function space.
     * \param waveNumber Wave number.
     *
     * See \ref helmholtz_3d for the definition of the wave number. */
    Helmholtz3dHypersingularOperator(
            const Space<BasisFunctionType>& testSpace,
            const Space<BasisFunctionType>& trialSpace,
            KernelType waveNumber) :
        Base(testSpace, trialSpace, waveNumber)
    {}
};

} // namespace Bempp

#endif