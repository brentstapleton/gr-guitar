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
#include "reverb_impl.h"

namespace gr {
  namespace guitar {

    reverb::sptr
    reverb::make(bool enabled, double samp_rate, const std::string& comb_coeff_mode, const std::string& allpass_coeff_mode, double wet_gamma)
    {
      return gnuradio::get_initial_sptr
        (new reverb_impl(enabled, samp_rate, comb_coeff_mode, allpass_coeff_mode, wet_gamma));
    }


    /*
     * The private constructor
     */
    reverb_impl::reverb_impl(bool enabled, double samp_rate, const std::string& comb_coeff_mode, const std::string& allpass_coeff_mode, double wet_gamma)
      : gr::sync_block("reverb",
              gr::io_signature::make(<+MIN_IN+>, <+MAX_IN+>, sizeof(<+ITYPE+>)),
              gr::io_signature::make(<+MIN_OUT+>, <+MAX_OUT+>, sizeof(<+OTYPE+>)))
    {}

    /*
     * Our virtual destructor.
     */
    reverb_impl::~reverb_impl()
    {
    }

    int
    reverb_impl::work(int noutput_items,
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

