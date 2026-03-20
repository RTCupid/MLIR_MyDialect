add_mlir_dialect_library(MyDialectIR
  MyDialectBase.cpp
  MyDialectOps.cpp

  DEPENDS
  MyDialectIRIncGen

  LINK_LIBS PUBLIC
  MLIRIR
  MLIRSupport
)

install(TARGETS MyDialectIR
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
)
