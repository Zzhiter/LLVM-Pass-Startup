#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {
  class MyModulePass : public ModulePass {
  public:
    static char ID;
    MyModulePass() : ModulePass(ID) {}

    bool runOnModule(Module &M) override {
      // 遍历模块中的函数
      for (Function &F : M) {
        // 遍历每个函数中的基本块
        for (BasicBlock &BB : F) {
          // 遍历每个基本块中的指令
          for (Instruction &I : BB) {
            // 在这里执行你的操作，例如输出指令信息
            errs() << "Instruction: " << I << "\n";
          }
        }
      }
      return false; // 在这个示例中，我们不对模块进行更改
    }
  };
}

char MyModulePass::ID = 0;
static RegisterPass<MyModulePass> X("my-module-pass", "Description of My Module Pass");
