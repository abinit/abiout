/**
 * @file include/./ddboutcar.hpp
 *
 * @brief Read an OUTCAR file and store the Dynamical Matrix
 *
 * @author Jordan Bieder <jordan.bieder@uliege.be>
 *
 * @copyright Copyright 2020 Jordan Bieder
 *
 * This file is part of Agate.
 *
 * Agate is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Agate is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Agate.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef DDBOUTCAR_HPP
#define DDBOUTCAR_HPP

#ifdef _WIN32
#include "base/win32.hpp"
#endif

#ifdef HAVE_CONFIG_H
#include "agate.h"
#undef HAVE_CONFIG_H
#endif

#include "io/ddb.hpp"
#include "io/outcar.hpp"

/** 
 *
 */
class DdbOutcar : public Outcar, public Ddb {

  private :

  protected :

  public :

    /**
     * Constructor.
     */
    DdbOutcar();

    /**
     * Destructor.
     */
    virtual ~DdbOutcar();

    /**
     * Fill a DDB with the content of a file.
     * @param filename The name of the input file to read.
     */
    virtual void readFromFile(const std::string& filename);

};

#endif  // DDBOUTCAR_HPP