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
#include "laplace_beltrami_3d_operator.hpp"
#include "../fiber/explicit_instantiation.hpp"
#include "discrete_boundary_operator.hpp"
#include "Komplex_LinearProblem.h"

namespace Bempp {

namespace {


//template <typename ValueType>
//void solveWithAmesos(Komplex_LinearProblem& problem,
//                     Amesos_BaseSolver& solver,
//                     arma::Mat<ValueType>& solution,
//                     const arma::Mat<ValueType>& rhs);

//template <>
//void solveWithAmesos<std::complex<double> >(Komplex_LinearProblem& problem,
//                                            Amesos_BaseSolver& solver,
//                                            arma::Mat<std::complex<double> >& armaSolution,
//                                            const arma::Mat<std::complex<double> >& armaRhs)
//{

//    const size_t rowCount = armaRhs.n_rows;
//    assert(rowCount == armaSolution.n_rows);
//    const size_t rhsCount = armaRhs.n_cols;
//    assert(rhsCount == armaSolution.n_cols);




//    Epetra_Map map((int) rowCount, 0 /* base index */, Epetra_SerialComm());
//    Epetra_MultiVector solution(View, map, armaSolution.memptr(),
//                                rowCount, rhsCount);
//    Epetra_MultiVector rhs(View, map, const_cast<double*>(armaRhs.memptr()),
//                           rowCount, rhsCount);
//    problem.SetLHS(&solution);
//    problem.SetRHS(&rhs);

//    if (solver.Solve() != 0)
//        throw std::runtime_error("solveWithAmesos(): solve failed");



//}



//template <typename ValueType>
//class DiscreteHelmholtz3dOsrcDtnOperator :
//        public DiscreteBoundaryOperator<ValueType>
//{
//public:

//    typedef DiscreteBoundaryOperator<ValueType> Base;

//    DiscreteHelmholtz3dOsrcDtnOperator(const shared_ptr<const Epetra_CrsMatrix>& identity,
//                                       const shared_ptr<const Epetra_CrsMatrix>& laplaceBeltrami,
//                                       int numberOfPadeTerms):

//        m_identity(identity),
//        m_laplaceBeltrami(laplaceBeltrami),
//        m_numberOfPadeTerms(numberOfPadeTerms) {}

//    virtual unsigned int rowCount() const {

//        return m_identity->NumGlobalRows();
//    }

//    virtual unsigned int columnCount() const {

//        return m_identity->NumGlobalCols();

//    }

//private:

//    const shared_ptr<const Epetra_CrsMatrix>& m_identity;
//    const shared_ptr<const Epetra_CrsMatrix>& m_laplaceBeltrami;
//    int m_numberOfPadeTerms;


//}

template <typename BasisFunctionType_>
class Helmholtz3dOsrcDtnOperator :
        public AbstractBoundaryOperator<BasisFunctionType_,typename Fiber::ScalarTraits<BasisFunctionType_>::ComplexType>
{

public:

    typedef AbstractBoundaryOperator<BasisFunctionType_,typename Fiber::ScalarTraits<BasisFunctionType_>::ComplexType> Base;
    typedef typename Base::BasisFunctionType BasisFunctionType;
    typedef typename Base::ResultType ResultType;
    typedef typename Base::CoordinateType CoordinateType;

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

        BoundaryOperator<BasisFunctionType,ResultType> laplaceBeltrami =
                laplaceBeltrami3dOperator<BasisFunctionType,ResultType>(
                                          make_shared_from_const_ref(context),
                                          this->domain(),
                                          this->range(),
                                          this->dualToRange());
        return laplaceBeltrami.abstractOperator()->assembleWeakForm(context);


    }



private:

    int m_numberOfPadeTerms;

};


}



template <typename BasisFunctionType>
BoundaryOperator<BasisFunctionType, typename Fiber::ScalarTraits<BasisFunctionType>::ComplexType>
helmholtz3dOsrcDtnOperator(
        const shared_ptr<const Context<BasisFunctionType,
            typename Fiber::ScalarTraits<BasisFunctionType>::ComplexType> >& context,
        const shared_ptr<const Space<BasisFunctionType> >& domain,
        const shared_ptr<const Space<BasisFunctionType> >& range,
        const shared_ptr<const Space<BasisFunctionType> >& dualToRange,
        int numberOfPadeTerms,
        const std::string& label,
        int symmetry)
{

    typedef typename Fiber::ScalarTraits<BasisFunctionType>::ComplexType ResultType;
    typedef AbstractBoundaryOperator<BasisFunctionType,ResultType> AbstractOp;
    typedef Helmholtz3dOsrcDtnOperator<BasisFunctionType> AbstractOsrcOp;

    shared_ptr<AbstractOp> abstractOsrcOperator(new AbstractOsrcOp(
                                                    domain,range,dualToRange,
                                                    numberOfPadeTerms,label,symmetry));


    return BoundaryOperator<BasisFunctionType,ResultType>(context,abstractOsrcOperator);

}


#define INSTANTIATE_NONMEMBER_CONSTRUCTOR(BASIS) \
    template BoundaryOperator<BASIS, typename Fiber::ScalarTraits< BASIS >::ComplexType > \
    helmholtz3dOsrcDtnOperator( \
        const shared_ptr<const Context<BASIS, typename Fiber::ScalarTraits< BASIS >::ComplexType> >&, \
        const shared_ptr<const Space<BASIS> >&, \
        const shared_ptr<const Space<BASIS> >&, \
        const shared_ptr<const Space<BASIS> >&, \
        int numberOfPadeTerms, \
        const std::string&, \
        int)
FIBER_ITERATE_OVER_BASIS_TYPES(INSTANTIATE_NONMEMBER_CONSTRUCTOR);


}
