[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 100
  ny = 10
  xmin = 0.0
  xmax = 0.304
  ymin = 0.0
  ymax = 0.0257
[]

[Problem]
  type = FEProblem
  coord_type = RZ
  rz_coord_axis = X
[]

[Variables]
  [pressure]
    # Adds linear Lagrange variable by default
  []
[]

[Kernels]
  [diffusion]
    type = ADDiffusion
    variable = pressure
  []
[]

[BCs]
  [inlet]
    type = ADDirichletBC
    variable = pressure
    boundary = left
    value = 4000 #Pa
  []
  [outlet]
    type = ADDirichletBC
    variable = pressure
    boundary = right
    value = 0
  []
[]

[Executioner]
  type = Steady
  solve_type = NEWTON

  # Set PETSC parameters
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = ' hypre    boomeramg'
[]

[Outputs]
  exodus = true
[]
