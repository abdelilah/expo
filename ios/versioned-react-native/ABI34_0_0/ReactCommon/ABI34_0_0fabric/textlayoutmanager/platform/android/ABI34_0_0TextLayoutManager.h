/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <memory>

#include <ReactABI34_0_0/attributedstring/AttributedString.h>
#include <ReactABI34_0_0/attributedstring/ParagraphAttributes.h>
#include <ReactABI34_0_0/core/LayoutConstraints.h>
#include <ReactABI34_0_0/uimanager/ContextContainer.h>

namespace facebook {
namespace ReactABI34_0_0 {

class TextLayoutManager;

using SharedTextLayoutManager = std::shared_ptr<const TextLayoutManager>;

/*
 * Cross platform facade for Android-specific TextLayoutManager.
 */
class TextLayoutManager {
 public:
  TextLayoutManager(const SharedContextContainer &contextContainer)
      : contextContainer_(contextContainer){};
  ~TextLayoutManager();

  /*
   * Measures `attributedString` using native text rendering infrastructure.
   */
  Size measure(
      AttributedString attributedString,
      ParagraphAttributes paragraphAttributes,
      LayoutConstraints layoutConstraints) const;

  /*
   * Returns an opaque pointer to platform-specific TextLayoutManager.
   * Is used on a native views layer to delegate text rendering to the manager.
   */
  void *getNativeTextLayoutManager() const;

 private:
  void *self_;

  SharedContextContainer contextContainer_;
};

} // namespace ReactABI34_0_0
} // namespace facebook
