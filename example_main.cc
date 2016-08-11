#include "keras_model.h"

#include <iostream>
#include <chrono>
#include <vector>

int main() {
  std::vector<float> q_zero;
  for (unsigned i = 0; i < 38; i++) q_zero.push_back(0.0);
  keras::DataChunkFlat *sample = new keras::DataChunkFlat();
  sample->set_data(q_zero);

  // std::vector<float> q_one;
  // for (unsigned i = 0; i < 38; i++) q_one.push_back(1.0);
  // keras::DataChunkFlat *sample1 = new keras::DataChunkFlat();
  // sample1->set_data(q_one);

  keras::KerasModel m("./qsc.net");

  auto start = std::chrono::steady_clock::now();
  std::vector<float> prediction = m.compute_output(sample);
  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;
  std::cout << std::chrono::duration<double, std::nano>(diff).count()
            << " nano-seconds" << std::endl;

  // Slice into COM and COM_Jacobian

  // std::cout << "Prediction: " << std::endl;
  // for (std::vector<float>::const_iterator it = prediction.begin();
  //      it != prediction.end(); ++it)
  //   std::cout << *it << ' ';

  return 0;
}
