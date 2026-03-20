add_mlir_library(MLIRMyDialectConversion
  Passes.cpp
  LowerToTarget.cpp

  LINK_LIBS PUBLIC
  MyDialectIR
  MLIRIR
  MLIRPass
)

install(TARGETS MLIRMyDialectConversion
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
)
