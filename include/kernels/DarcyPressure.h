#pragma once

// Including base AD Kernel Grad method
#include "ADKernelGrad.h"

class DarcyPressure : public ADKernelGrad
{
public:
  static InputParameters validParams();
  DarcyPressure(const InputParameters & parameters);
protected:
  virtual ADRealVectorValue precomputeQpResidual() override;
  // const Real & _permeability;
  // const Real & _viscosity;
  const ADMaterialProperty<Real> & _permeability;
  const ADMaterialProperty<Real> & _viscosity;
};
