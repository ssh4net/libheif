/*
 * HEIF codec.
 * Copyright (c) 2023 Dirk Farin <dirk.farin@gmail.com>
 *
 * This file is part of libheif.
 *
 * libheif is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * libheif is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libheif.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBHEIF_ENCODER_KVAZAAR_H
#define LIBHEIF_ENCODER_KVAZAAR_H

#include "libheif/common_utils.h"

/* TODO: check whether this is also the case with kvazaar.
 *
 * Image sizes in HEVC: since HEVC does not allow for odd image dimensions when
   using chroma 4:2:0, our strategy is as follows.

   - Images with odd dimensions are extended with an extra row/column which
     contains a copy of the border.
   - The HEVC image size generated by kvazaar is rounded up to the CTU size (?)
     and the conformance window has to be respected.
   - We add an additional crop transform to remove the extra row/column.
 */


const struct heif_encoder_plugin* get_encoder_plugin_kvazaar();

#if PLUGIN_KVAZAAR
extern "C" {
MAYBE_UNUSED LIBHEIF_API extern heif_plugin_info plugin_info;
}
#endif

#endif