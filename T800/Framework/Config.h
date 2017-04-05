/*********************************************************
* Copyright (C) 2017 Daniel Enriquez (camus_mm@hotmail.com)
* All Rights Reserved
*
* You may use, distribute and modify this code under the
* following terms:
* ** Do not claim that you wrote this software
* ** A mention would be appreciated but not needed
* ** I do not and will not provide support, this software is "as is"
* ** Enjoy, learn and share.
*********************************************************/

#ifndef T800_CONFIG_H
#define T800_CONFIG_H

#define D3DX 1
#define OGLES 2
#define OGL 3

#define DRIVER_SELECTED OGL

#if   DRIVER_SELECTED == OGLES
	#define USING_OPENGL_ES
#elif DRIVER_SELECTED == D3DX
	#define USING_D3D11
#elif DRIVER_SELECTED == OGL
	#define USING_OPENGL
#endif

#endif