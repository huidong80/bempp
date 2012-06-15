%{
#include "assembly/linear_operator.hpp"
#include <complex>
%}

// TODO
// %include "linear_operator_docstrings.i"

namespace Bempp
{

template <typename BasisFunctionType, typename ResultType> class LinearOperator;

template <typename BasisFunctionType> class GridFunction;
template <typename BasisFunctionType> class Space;
class AssemblyOptions;
class Symmetry;

%extend LinearOperator
{
    // this function is only for internal use
    %ignore constituentOperators;

    // this function is only for internal use
    %ignore constituentOperatorWeights;
}

} // namespace Bempp

%include "assembly/linear_operator.hpp"

namespace Bempp
{
BEMPP_PYTHON_INSTANTIATE_CLASS_TEMPLATED_ON_BASIS_AND_RESULT(LinearOperator);
}

%pythoncode %{

class LinearOperator(object):
    pass
    # TODO: docs

%}
