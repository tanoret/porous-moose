#include "DarcyPressure.h"

registerMooseObject("BabblerApp", DarcyPressure);

InputParameters DarcyPressure::validParams()
{
  InputParameters params = ADKernelGrad::validParams();
  params.addClassDescription("Compute the diffusion term for Darcy pressure ($p$) equation: "
                             "$-\\nabla \\cdot \\frac{\\mathbf{K}}{\\mu} \\nabla p = 0$");

  params.addRequiredParam<Real>("permeability",
                                "The isotropic permeability $K$ in the porous medium.");

  params.addParam<Real>("viscosity",
                        7.98e-04,
                        "The dynamic viscosity $($\\mu$) of the fluid - the default value is 7.94e-04 Pa.s");

  return params;
};

DarcyPressure::DarcyPressure(const InputParameters & parameters)
  : ADKernelGrad(parameters),
    _permeability(getParam<Real>("permeability")),
    _viscosity(getParam<Real>("viscosity"))
{
  if (_viscosity == 0)
    paramError("viscosity", "The viscosity must be a non-zero real number.");
}

ADRealVectorValue DarcyPressure::precomputeQpResidual()
{
  return (_permeability / _viscosity) * _grad_u[_qp];
}
