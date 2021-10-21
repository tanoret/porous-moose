#pragma once

// Include basic material object and linear interpolation function
#include "ADMaterial.h"
#include "LinearInterpolation.h"

class PackedColumn : public ADMaterial
{
public:

  static InputParameters validParams();
  PackedColumn(const InputParameters & parameters);

protected:

  virtual void computeQpProperties() override;

  // Parameters defining the packed bed
  const Real & _diameter;
  const Real & _input_viscosity;

  // Declare the linear interpolation object
  LinearInterpolation _permeability_interpolation;

  // Material property values that hold the values for permeability and dynamic viscosity
  ADMaterialProperty<Real> & _permeability;
  ADMaterialProperty<Real> & _viscosity;

};
