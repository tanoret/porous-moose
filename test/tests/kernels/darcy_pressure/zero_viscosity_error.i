[Mesh]
  type = GeneratedMesh
  dim = 1
[]

[Problem]
  solve = false
[]

[Variables]
  [u]
  []
[]

[Kernels]
  [diffusion]
    type = DarcyPressure
    variable = u
    permeability = 0.8451e-09 # (m^2)
    viscosity = 0.0
  []
[]

[Executioner]
  type = Steady
[]
