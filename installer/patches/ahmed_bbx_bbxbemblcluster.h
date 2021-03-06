/*
    AHMED -- Another software library on Hierarchical Matrices for
             Elliptic Differential equations

    Copyright (c) 2012 Mario Bebendorf

    You should have received a copy of the license along with
    this software; if not, see AHMED's internet site.
*/


/*
    This file has been added by the authors of BEM++.

    Summary of changes:

    - 7/05/2013: initial version. This class is identical to bemblcluster
      except that it derives from blcluster (not blcluster_geo) and row and
      column clusters must be bbxbemcluster objects (not bemcluster objects).
*/

#ifndef BBXBEMBLCLUSTER_H
#define BBXBEMBLCLUSTER_H

#include "blcluster.h"
#include "bbxbemcluster.h"

template<class T1, class T2>
class bbxbemblcluster : public blcluster
{
  bbxbemcluster<T1>* cl1;
  bbxbemcluster<T2>* cl2;

public:
  bbxbemblcluster(unsigned i1, unsigned i2, unsigned m1, unsigned m2)
      : blcluster(i1, i2, m1, m2) { }

  bbxbemblcluster(bbxbemcluster<T1>* p1, bbxbemcluster<T2>* p2) : blcluster(p1, p2),
      cl1(p1), cl2(p2) { }

  //! copy constructor
  bbxbemblcluster(bbxbemblcluster<T1,T2>* bl) :
      blcluster(bl), cl1(bl->cl1), cl2(bl->cl2) { }

  blcluster* clone(cluster* p1, cluster* p2) const {
    return new bbxbemblcluster((bbxbemcluster<T1>*)p1, (bbxbemcluster<T2>*)p2);
  }

  bbxbemcluster<T1>* getcl1() const { return cl1; }
  bbxbemcluster<T2>* getcl2() const { return cl2; }
};

#endif
