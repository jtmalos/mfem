// Copyright (c) 2010, Lawrence Livermore National Security, LLC. Produced at
// the Lawrence Livermore National Laboratory. LLNL-CODE-443211. All Rights
// reserved. See file COPYRIGHT for details.
//
// This file is part of the MFEM library. For more information and source code
// availability see http://mfem.org.
//
// MFEM is free software; you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License (as published by the Free
// Software Foundation) version 2.1 dated February 1999.

#ifndef MFEM_QUADRILATERAL
#define MFEM_QUADRILATERAL

#include "../config/config.hpp"
#include "element.hpp"

namespace mfem
{

/// Data type quadrilateral element
class Quadrilateral : public Element
{
protected:

   static const int edges[4][2];


public:
   static const size_t NUM_INDICES = 4;

   Quadrilateral() : Element(Geometry::SQUARE, NULL, 4) { }
   Quadrilateral(int *alloc, int *attri) : Element(Geometry::SQUARE, alloc, 4) { }


   /// Constructs quadrilateral by specifying the indices and the attribute.
   /// We also allow an external memory location for the indices to be
   /// Specified.
   Quadrilateral(const int *ind, int attr = 1,
         int *alloc = NULL);

   /// Constructs quadrilateral by specifying the indices and the attribute.
   /// We also allow an external memory location for the indices to be
   /// Specified.
   Quadrilateral(int ind1, int ind2, int ind3, int ind4, int attr = 1,
         int *alloc = NULL);


   /// Return element's type
   int GetType() const { return Element::QUADRILATERAL; }

   /// Set the vertices according to the given input.
   virtual void SetVertices(const int *ind);

   /// Returns the indices of the element's vertices.
   virtual void GetVertices(Array<int> &v) const;

   virtual int *GetVertices() { return indices; }

   virtual int GetNVertices() const { return 4; }

   virtual int GetNEdges() const { return (4); }

   virtual const int *GetEdgeVertices(int ei) const
   { return (edges[ei]); }

   virtual int GetNFaces(int &nFaceVertices) const
   { nFaceVertices = 0; return 0; }

   virtual const int *GetFaceVertices(int fi) const { return NULL; }

   virtual Element *Duplicate(Mesh *m) const
   { return new Quadrilateral(indices, attribute); }

   virtual ~Quadrilateral() { }
};

extern BiLinear2DFiniteElement QuadrilateralFE;

}

#endif
