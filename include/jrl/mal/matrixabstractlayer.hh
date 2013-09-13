 /*
 * Copyright 2007, 2008, 2009, 2010,
 * Luis Degaldo,
 * Francois Keith,
 * Florent Lamiraux,
 * Anthony Mallet,
 * Olivier Stasse,
 *
 * CNRS/AIST
 *
 * This file is part of MatrixAbstractLayer.
 * MatrixAbstractLayer is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * MatrixAbstractLayer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * You should have received a copy of the GNU Lesser General Public License
 * along with MatrixAbstractLayer.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * \file MatrixAbstractLayer.h
 *
 * @ingroup linearalgebra
 * This header file intend to define an abstraction layer
 * to allow the use of diverse matrix libraries.
 * This is supposed to solve the dependency to a particular
 * matrix library.
 * If you do not like the current two solutions:
 *  - Eigen
 *  - uBLAS + LAPACK
 *
 * you can implement your own.
 *
 *
 * For small matrices it is sometimes more efficient
 * to use specific data structure.
 * For this reason an abstract interface for
 * small 3x3 and 4x4 matrices as well as vectors
 * is also provided. MatrixAbstractLayerT3D defines a
 * specific implementation for small 3x3, 4x4 and
 * small vectors.
 *
 * We however assume that the library used
 * is based on C++ classes and has a sensible implementation
 * of matrix operators.
 *
 * (c) 2006 , Olivier Stasse and Florent Lamiraux JRL-Japan, CNRS-AIST, ISRI.
 */


#ifndef _MATRIX_ABSTRACT_LAYER_H_
#  define _MATRIX_ABSTRACT_LAYER_H_

// Define which type of linear algebra package and which type of small matrix and vector package.
# include <jrl/mal/configmal.hh>

  /*Documentation*/
# include <jrl/mal/matrixabstractlayerdoc.hh>
# include <jrl/mal/matrixabstractlayersmall.hh>


  /*Boost or Eigen*/
# if _EIGEN_MATRIX_ == 1
#  include <jrl/mal/matrixabstractlayereigen.hh>
# elif _BOOST_MATRIX_ == 1
#  include <jrl/mal/matrixabstractlayerboost.hh>
# endif

  /*Small with T3D, R3D and V3D or by default*/
# if _T3D_R3D_V3D_ == 1
#  include <jrl/mal/matrixabstractlayert3d.hh>
# else
#  include "jrl/mathtools/constants.hh"
#  include <jrl/mal/matrixabstractlayervector3jrlmath.hh>
#  include <jrl/mal/matrixabstractlayervector4jrlmath.hh>
#  include <jrl/mal/matrixabstractlayermatrix3x3jrlmath.hh>
#  include <jrl/mal/matrixabstractlayermatrix4x4jrlmath.hh>
# endif

# define MATRIX_VERSION 1

# include <jrl/mal/matrixabstractlayercheck.hh>

#endif /* _MATRIX_ABSTRACT_LAYER_H_ */
