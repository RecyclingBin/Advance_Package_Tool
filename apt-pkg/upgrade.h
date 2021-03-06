// -*- mode: cpp; mode: fold -*-
// Description								/*{{{*/
/* ######################################################################

   Upgrade - Upgrade/DistUpgrade releated code
   
   ##################################################################### */
									/*}}}*/

#ifndef PKGLIB_UPGRADE_H
#define PKGLIB_UPGRADE_H

#include <stddef.h>
#include <apt-pkg/macros.h>

class pkgDepCache;
class OpProgress;

namespace APT {
   namespace Upgrade {
      // FIXME: make this "enum class UpgradeMode {" once we enable c++11
      enum UpgradeMode {
	 ALLOW_EVERYTHING = 0,
         FORBID_REMOVE_PACKAGES = 1,
         FORBID_INSTALL_NEW_PACKAGES = 2
      };
      bool Upgrade(pkgDepCache &Cache, int UpgradeMode, OpProgress * const Progress = NULL);
   }
}

// please use APT::Upgrade::Upgrade() instead
APT_DEPRECATED bool pkgDistUpgrade(pkgDepCache &Cache, OpProgress * const Progress = NULL);
APT_DEPRECATED bool pkgAllUpgrade(pkgDepCache &Cache, OpProgress * const Progress = NULL);

bool pkgMinimizeUpgrade(pkgDepCache &Cache);
#endif
