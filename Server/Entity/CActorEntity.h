//================= IV:Network - https://github.com/GTA-Network/IV-Network =================
//
// File: CActorEntity.h
// Project: Server.Core
// Author: xForce <xf0rc3.11@gmail.com>
// License: See LICENSE in root directory
//
//==============================================================================

#ifndef CActorEntity_h
#define CActorEntity_h

#include "CNetworkEntity.h"

class CActorEntity : public CNetworkEntity {
private:

public:
	CActorEntity();
	~CActorEntity();

	bool Create() {return true;}
	bool Destroy() {return true;}
};

#endif // CActorEntity_h