/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <executorch/kernels/portable/cpu/pattern/pattern.h>
#include <executorch/runtime/kernel/kernel_includes.h>
#include <cmath>

namespace torch {
namespace executor {
namespace native {

Tensor& isnan_out(RuntimeContext& ctx, const Tensor& in, Tensor& out) {
  // Lambda is syntactic sugar needed to workaround compilation on some older
  // non-compatible distros where isnan is returning int rather than bool
  return internal::unary_ufunc_realhb_to_bool(
      [](double x) -> bool { return std::isnan(x); }, ctx, in, out);
}

} // namespace native
} // namespace executor
} // namespace torch
