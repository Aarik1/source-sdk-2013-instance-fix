//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================//

#ifndef ENTITYDEFS_H
#define ENTITYDEFS_H
#ifdef _WIN32
#pragma once
#endif


#define MAX_ENTITY_NAME_LEN			256

#define MAX_IO_NAME_LEN				256

// Hammer++ outputs with 0x2C as a delimiter. CSGO hammer outputs 0x1b. Probably a bug with hammer++.
// No point in setting it to 0x1b though due to SDK 2013 hammer not supporting func_instance_io_proxy.
// Although this will work in Garry's Mod as it uses 0x2C aswell.
#define VMF_IOPARAM_STRING_DELIMITER 0x2C 




#endif // ENTITYDEFS_H
