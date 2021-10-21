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
  []
[]

[Materials]
  [filer]
    type = PackedColumn
    viscosity = 0.0 #Pa.s
  []
[]

[Executioner]
  type = Steady
[]
