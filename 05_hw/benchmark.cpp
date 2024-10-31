#include <benchmark/benchmark.h>
#include "stack.h"

class StackBench : public benchmark::Fixture {
public:
  void SetUp(::benchmark::State& state) {
    stack = new Stack();
  }

  void TearDown(::benchmark::State& state) {
    delete stack;
  }
  Stack* stack;
};


BENCHMARK_DEFINE_F(StackBench, PushTest)(benchmark::State& st) {
   for (auto _ : st) {
    for(int i=0; i < st.range(0); i++){
      stack->push(i);
    }
  }
}

BENCHMARK_DEFINE_F(StackBench, PopTest)(benchmark::State& st) {
    for(int i=0; i < st.range(0); i++){
      stack->push(i);
    }
   for (auto _ : st) {
    for(int i=0; i < st.range(0); i++){
      stack->pop();
    }
  }
}
BENCHMARK_REGISTER_F(StackBench, PushTest)->Arg(10)->Arg(100)->Arg(1000)->Arg(10000)->Arg(100000)->Arg(1000000);
BENCHMARK_REGISTER_F(StackBench, PopTest)->Arg(10)->Arg(100)->Arg(1000)->Arg(10000)->Arg(100000)->Arg(1000000);

BENCHMARK_MAIN();