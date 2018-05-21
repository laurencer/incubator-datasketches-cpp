/*
 * Copyright 2018, Oath Inc. Licensed under the terms of the
 * Apache License 2.0. See LICENSE file at the project root for terms.
 */

#ifndef KLL_HELPER_HPP_
#define KLL_HELPER_HPP_

#include <random>

namespace sketches {

static std::independent_bits_engine<std::mt19937, 1, size_t> random_bit;

class kll_helper {
  public:
    static bool is_even(size_t value);
    static bool is_odd(size_t value);
    static uint8_t floor_of_log2_of_fraction(uint64_t numer, uint64_t denom);
    static uint8_t ub_on_num_levels(uint64_t n);
    static uint32_t compute_total_capacity(uint16_t k, uint8_t m, uint8_t num_levels);
    static uint32_t level_capacity(uint16_t k, uint8_t numLevels, uint8_t height, uint8_t minWid);
    static uint32_t int_cap_aux(uint16_t k, uint8_t depth);
    static uint32_t int_cap_aux_aux(uint16_t k, uint8_t depth);
    static uint64_t sum_the_sample_weights(uint8_t num_levels, const uint32_t* levels);
    static void randomly_halve_down(float* buf, size_t start, size_t length);
    static void randomly_halve_up(float* buf, size_t start, size_t length);
    static void merge_sorted_arrays(float* buf_a, size_t start_a, size_t len_a, float* buf_b, size_t start_b, size_t len_b, float* buf_c, size_t start_c);

    struct compress_result {
      uint8_t final_num_levels;
      uint32_t final_capacity;
      uint32_t final_pop;
    };
    static compress_result general_compress(uint16_t k, uint8_t m, uint8_t num_levels_in, float* in_buf,
        uint32_t* in_levels, float* out_buf, uint32_t* out_levels, bool is_level_zero_sorted);

  private:
    static size_t deterministic_offset();

};

}

#endif