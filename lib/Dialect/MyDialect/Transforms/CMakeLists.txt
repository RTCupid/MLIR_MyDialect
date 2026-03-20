add_mlir_library(MLIRMyDialectTransforms
  Passes.cpp
  GroupedPasses.cpp
  ExampleTransform.cpp

  LINK_LIBS PUBLIC
  MyDialectIR
  MLIRArithDialect
  MLIRFuncDialect
  MLIRIR
  MLIRPass
)

install(TARGETS MLIRMyDialectTransforms
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
)
