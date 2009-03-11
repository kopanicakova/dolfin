// Copyright (C) 2009 Anders Logg.
// Licensed under the GNU LGPL Version 2.1.
//
// First added:  2009-03-11
// Last changed: 2009-03-11

#include <dolfin/mesh/Cell.h>
#include "Data.h"

using namespace dolfin;

//-----------------------------------------------------------------------------
Data::Data()
  : x(0), t(0.0), _cell(0), _facet(-1)
{
  // Do nothing
}
//-----------------------------------------------------------------------------
Data::Data(const Cell& cell, int facet)
  : x(0), t(0.0), _cell(&cell), _facet(facet)
{
  // Do nothing
}
//-----------------------------------------------------------------------------
Data::~Data()
{
  // Do nothing
}
//-----------------------------------------------------------------------------
const Cell& Data::cell() const
{
  if (!_cell)
    error("Current cell is unknown.");

  return *_cell;
}
//-----------------------------------------------------------------------------
dolfin::uint Data::facet() const
{
  if (_facet < 0)
    error("Current facet is unknown.");

  return static_cast<uint>(_facet);
}
//-----------------------------------------------------------------------------
Point Data::normal() const
{
  return cell().normal(facet());
}
//-----------------------------------------------------------------------------
bool Data::on_facet() const
{
  return _facet >= 0;
}
//-----------------------------------------------------------------------------
dolfin::uint Data::geometric_dimension() const
{
  dolfin_assert(_cell);
  return _cell->mesh().geometry().dim();
}
//-----------------------------------------------------------------------------
