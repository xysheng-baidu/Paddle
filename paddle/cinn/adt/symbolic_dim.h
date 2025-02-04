// Copyright (c) 2023 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "paddle/cinn/adt/adt.h"
#include "paddle/cinn/adt/unique_id.h"

namespace cinn::adt {

DEFINE_ADT_TAG(tSymbolicDim);

using SymbolicDim = tSymbolicDim<UniqueId>;

}  // namespace cinn::adt

namespace std {

template <>
struct hash<cinn::adt::SymbolicDim> final {
  std::size_t operator()(const cinn::adt::SymbolicDim& symbolic_dim) const {
    return symbolic_dim.value().unique_id();
  }
};

}  // namespace std
