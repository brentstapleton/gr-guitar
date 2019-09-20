/* -*- c++ -*- */
/*
 * Copyright 2019 Ashish Chaudhari.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_GUITAR_WAH_FILTER_IMPL_H
#define INCLUDED_GUITAR_WAH_FILTER_IMPL_H

#include <guitar/wah_filter.h>

namespace gr {
  namespace guitar {

    class wah_filter_impl : public wah_filter
    {
     private:
      // Nothing to declare in this block.

     public:
      wah_filter_impl(bool enabled, double samp_rate, std::string envelope_src, double cutoff_freq_min, double cutoff_freq_max, double lfo_freq, double damp);
      ~wah_filter_impl();

      // Where all the action really happens
      int work(
              int noutput_items,
              gr_vector_const_void_star &input_items,
              gr_vector_void_star &output_items
      );
    };

  } // namespace guitar
} // namespace gr

#endif /* INCLUDED_GUITAR_WAH_FILTER_IMPL_H */

