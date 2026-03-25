#ifndef MYDIALECT_PASSES_TD
#define MYDIALECT_PASSES_TD

include "mlir/Pass/PassBase.td"

def MyTransform : Pass<"my-transform"> {
  let summary = "My pass that does something";
  let description = [{
    This is a sample pass that demonstrates how to define a pass using TableGen.
  }];
  let constructor = "mlir::my_project::createMyTransformPass()";
}

#endif // MYDIALECT_PASSES_TD
