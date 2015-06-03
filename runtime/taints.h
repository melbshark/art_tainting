/*
 * Copyright (C) 2015 Khaled Blah
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ART_RUNTIME_TAINTS_H_
#define ART_RUNTIME_TAINTS_H_

#include "offsets.h"

#define TAINT_NUMBER_OF 256

namespace art {

typedef unsigned long taint;

template<size_t pointer_size>
class Tainting {
 public:
  Tainting(size_t offset, taint value) : offset_(offset), value_(value) {
  }

  void SetOffset(size_t offset) {
    offset_ = offset;
  }

  template<size_t pointer_size>
  ThreadOffset<pointer_size> GetOffset() {
    return ThreadOffset<pointer_size> offset_;
  }

  void SetValue(taint value) {
    value_ = value;
  }

  taint GetValue() {
    return value_;
  }
 private:
  ThreadOffset<pointer_size> offset_;
  taint value_;
}

} // namespace art

#endif  // ART_RUNTIME_TAINTS_H_
