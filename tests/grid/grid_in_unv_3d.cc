// ---------------------------------------------------------------------
//
// Copyright (C) 2002 - 2018 by the deal.II authors
//
// This file is part of the deal.II library.
//
// The deal.II library is free software; you can use it, redistribute
// it, and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full text of the license can be found in the file LICENSE.md at
// the top level directory of deal.II.
//
// ---------------------------------------------------------------------


// read in a 3d file in the UNV format used by the Salome program

// the meshes used here were generated by Valentin Zingan using the Salome
// mesh generator

#include <deal.II/dofs/dof_handler.h>

#include <deal.II/grid/grid_generator.h>
#include <deal.II/grid/grid_in.h>
#include <deal.II/grid/grid_out.h>
#include <deal.II/grid/manifold_lib.h>
#include <deal.II/grid/tria.h>
#include <deal.II/grid/tria_accessor.h>
#include <deal.II/grid/tria_iterator.h>

#include <string>

#include "../tests.h"

template <int dim>
void
check_file(const std::string name, typename GridIn<dim>::Format format)
{
  Triangulation<dim> tria;
  GridIn<dim>        gi;
  gi.attach_triangulation(tria);
  gi.read(name, format);
  deallog << '\t' << tria.n_vertices() << '\t' << tria.n_cells() << std::endl;

  GridOut grid_out;
  grid_out.write_gnuplot(tria, deallog.get_file_stream());
}

void
filename_resolution()
{
  check_file<3>(std::string(SOURCE_DIR "/grid_in_unv_3d/3D"), GridIn<3>::unv);
  check_file<3>(std::string(SOURCE_DIR "/grid_in_unv_3d/salome_cube"),
                GridIn<3>::unv);
}


int
main()
{
  initlog();
  deallog.get_file_stream() << std::setprecision(2);

  filename_resolution();
}
