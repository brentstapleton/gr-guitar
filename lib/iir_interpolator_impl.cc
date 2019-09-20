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
#    include "config.h"
#endif

#include "iir_interpolator_impl.h"
#include <gnuradio/io_signature.h>

namespace gr { namespace guitar {

iir_interpolator::sptr iir_interpolator::make(int interpolation,
    const std::vector<double>& fftaps,
    const std::vector<double>& fbtaps)
{
    return gnuradio::get_initial_sptr(
        new iir_interpolator_impl(interpolation, fftaps, fbtaps));
}


/*
 * The private constructor
 */
iir_interpolator_impl::iir_interpolator_impl(int interpolation,
    const std::vector<double>& fftaps,
    const std::vector<double>& fbtaps)
    : gr::sync_interpolator("iir_interpolator",
          gr::io_signature::make(<+MIN_IN +>, <+MAX_IN +>, sizeof(<+ITYPE +>)),
          gr::io_signature::make(<+MIN_OUT +>, <+MAX_OUT +>, sizeof(<+OTYPE +>)),
          <+interpolation +>)
{
}

/*
 * Our virtual destructor.
 */
iir_interpolator_impl::~iir_interpolator_impl() {}

int iir_interpolator_impl::work(int noutput_items,
    gr_vector_const_void_star& input_items,
    gr_vector_void_star& output_items)
{
    const<+ITYPE +>* in = (const<+ITYPE +>*)input_items[0];
    <+OTYPE +>* out     = (<+OTYPE +>*)output_items[0];

    // Do <+signal processing+>

    // Tell runtime system how many output items we produced.
    return noutput_items;
}

}} // namespace gr::guitar
