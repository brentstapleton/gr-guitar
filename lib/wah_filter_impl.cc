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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "wah_filter_impl.h"

namespace gr {
  namespace guitar {

    wah_filter::sptr
    wah_filter::make(bool enabled, double samp_rate, std::string envelope_src, double cutoff_freq_min, double cutoff_freq_max, double lfo_freq, double damp)
    {
      return gnuradio::get_initial_sptr
        (new wah_filter_impl(enabled, samp_rate, envelope_src, cutoff_freq_min, cutoff_freq_max, lfo_freq, damp));
    }


    /*
     * The private constructor
     */
    wah_filter_impl::wah_filter_impl(bool enabled, double samp_rate, std::string envelope_src, double cutoff_freq_min, double cutoff_freq_max, double lfo_freq, double damp)
      : gr::sync_block("wah_filter",
              gr::io_signature::make(<+MIN_IN+>, <+MAX_IN+>, sizeof(<+ITYPE+>)),
              gr::io_signature::make(<+MIN_OUT+>, <+MAX_OUT+>, sizeof(<+OTYPE+>)))
    {}

    /*
     * Our virtual destructor.
     */
    wah_filter_impl::~wah_filter_impl()
    {
    }

    int
    wah_filter_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const <+ITYPE+> *in = (const <+ITYPE+> *) input_items[0];
      <+OTYPE+> *out = (<+OTYPE+> *) output_items[0];

      // Do <+signal processing+>

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace guitar */
} /* namespace gr */

