/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <stdint.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

// Note: Not everything is relevant to Redex in here. This should mostly 1:1
// map to the JSON config currently being passed to the baseline profile
// driver.

// TODO: These are all set to the same defaults which the baseline profile
//       driver sets for interactions. This should ideally be defined in one
//       external place and passed to both Redex and the driver.
struct BaselineProfileInteractionConfig {
  int64_t call_threshold = 1;
  bool classes = true;
  bool post_startup = true;
  bool startup = false;
  int64_t threshold = 80;
};

struct BaselineProfileOptions {
  bool oxygen_modules;
  bool strip_classes;
  bool use_redex_generated_profile;
  // This field isn't used currently by the driver. We currently pass a
  // `--betamap` flag to the driver to enable betamap 20% set inclusion, which
  // isn't ideal. TODO: The driver config JSON should be updated to use this.
  bool include_betamap_20pct_coldstart;
};

struct BaselineProfileConfig {
  std::unordered_map<std::string, BaselineProfileInteractionConfig>
      interaction_configs;
  std::vector<std::pair<std::string, std::string>> interactions;
  BaselineProfileOptions options;
};
