/**
 * @file include/./etsfnc.hpp
 *
 * @brief Read structure from ETSF-IO specification
 *
 * @author Jordan Bieder <jordan.bieder@cea.fr>
 *
 * @copyright Copyright 2018 Jordan Bieder
 *
 * This file is part of AbiOut.
 *
 * AbiOut is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * AbiOut is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with AbiOut.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef ETSFNC_HPP
#define ETSFNC_HPP

#ifdef _WIN32
#include "base/win32.hpp"
#endif

#ifdef HAVE_CONFIG_H
#include "agate.h"
#undef HAVE_CONFIG_H
#endif

#include "io/dtset.hpp"

/** 
 *
 */
class EtsfNC : public virtual Dtset {

  private :

  protected :

  public :

    /**
     * Constructor.
     */
    EtsfNC();

    /**
     * Destructor.
     */
    virtual ~EtsfNC();

    /**
     * Fill a Dtset from an poscar file.
     * @param filename The name of the input file to read.
     */
    virtual void readFromFile(const std::string& filename);
};

#endif  // ETSFNC_HPP
