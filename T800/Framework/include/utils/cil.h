#ifndef T800_CIL_H
#define T800_CIL_H

#include <string>
#include <fstream>
#include <iostream>
#include <cstddef>
#include <algorithm>
using namespace std;

#define CIL_LOG_OUTPUT 1

// Formats
#define CIL_PVRTC_2BPP_RGB_FMT		0
#define CIL_PVRTC_2BPP_RGBA_FMT		1
#define CIL_PVRTC_4BPP_RGB_FMT		2
#define CIL_PVRTC_4BPP_RGBA_FMT		3
#define CIL_PVRTCII_2BPP_RGB_FMT	4
#define CIL_PVRTCII_4BPP_RGB_FMT	5
#define CIL_ETC1_FMT				6
#define CIL_DXT1_FMT				7
#define CIL_DXT3_FMT				9
#define CIL_DXT5_FMT				11
#define CIL_ETC2_FMT				23 //ETC2 RGBA not RGBA, for that we have ETC1
#define CIL_RGBA32_FMT

//Channel types
#define CIL_CHT_UNSIGNED_BYTE_NORM			0
#define CIL_CHT_SIGNED_BYTE_NORM			1
#define CIL_CHT_UNSIGNED_BYTE				2
#define CIL_CHT_SIGNED_BYTE					3
#define CIL_CHT_UNSIGNED_SHORT_NORM			4
#define CIL_CHT_SIGNED_SHORT_NORM			5
#define CIL_CHT_UNSIGNED_SHORT				6
#define CIL_CHT_SIGNED_SHORT				7
#define CIL_CHT_UNSIGNED_INT_NORM			8
#define CIL_CHT_SIGNED_INT_NORM				9
#define CIL_CHT_UNSIGNED_INT				10
#define CIL_CHT_SIGNED_INT					11
#define CIL_CHT_FLOAT						12

// Return Errors
#define CIL_NOT_FOUND				0x0E2
#define CIL_CORRUPT					0x0E3
#define CIL_NO_MEMORY				0x0E4
#define CIL_PVR_V2_NOT_SUPPORTED	0x0E5
#define CIL_NOT_SUPPORTED_FILE		0x0E6
#define CIL_DDS_MALFORMED			0x0E7
#define CIL_NO_ERROR				0

// DDS Specific 
#define CIL_DDS_CAPS			0x00000001l
#define CIL_DDS_HEIGHT			0x00000002l
#define CIL_DDS_WIDTH			0x00000004l
#define CIL_DDS_PITCH			0x00000008l
#define CIL_DDS_PIXELFORMAT		0x00001000l
#define CIL_DDS_MIPMAPCOUNT		0x00020000l
#define CIL_DDS_LINEARSIZE		0x00080000l
#define CIL_DDS_DEPTH			0x00800000l
#define CIL_DDS_ALPHAPIXELS		0x00000001l
#define CIL_DDS_FOURCC			0x00000004l
#define CIL_DDS_RGB				0x00000040l
#define CIL_DDS_RGBA			0x00000041l
#define CIL_DDS_COMPLEX			0x00000008l
#define CIL_DDS_TEXTURE			0x00001000l
#define CIL_DDS_MIPMAP			0x00400000l
#define CIL_DDS_CUBEMAP			0x00000200l
#define CIL_DDS_CUBEMAP_POSITIVEX  0x00000400l
#define CIL_DDS_CUBEMAP_NEGATIVEX  0x00000800l
#define CIL_DDS_CUBEMAP_POSITIVEY  0x00001000l
#define CIL_DDS_CUBEMAP_NEGATIVEY  0x00002000l
#define CIL_DDS_CUBEMAP_POSITIVEZ  0x00004000l
#define CIL_DDS_CUBEMAP_NEGATIVEZ  0x00008000l
#define CIL_DDS_CUBEMAP_ALL_FACES  0x0000FC00l
#define CIL_DDS_VOLUME   0x00200000l
#define CIL_FOURCC_DXT1  0x31545844l 
#define CIL_FOURCC_DXT3  0x33545844l 
#define CIL_FOURCC_DXT5  0x35545844l 
#define CIL_FOURCC_RAW	 0

// KTX formats
#define CIL_ETC1_RGB8_OES						0x8D64
#define CIL_COMPRESSED_RGB_PVRTC_4BPPV1_IMG		0x8C00
#define CIL_COMPRESSED_RGB_PVRTC_2BPPV1_IMG		0x8C01
#define CIL_COMPRESSED_RGBA_PVRTC_4BPPV1_IMG	0x8C02
#define CIL_COMPRESSED_RGBA_PVRTC_2BPPV1_IMG	0x8C03
#define CIL_COMPRESSED_RGBA_PVRTC_2BPPV2_IMG	0x9137
#define CIL_COMPRESSED_RGBA_PVRTC_4BPPV2_IMG	0x9138
#define CIL_COMPRESSED_RGBA8_ETC2_EAC			0x9278
#define CIL_COMPRESSED_RGB_S3TC_DXT1_EXT		0x83F0
#define CIL_COMPRESSED_RGBA_S3TC_DXT1_EXT		0x83F1
#define CIL_COMPRESSED_RGBA_S3TC_DXT3_EXT		0x83F2
#define CIL_COMPRESSED_RGBA_S3TC_DXT5_EXT		0x83F3

// Props
#define CIL_ALPHA				(1 << 0)
#define CIL_RGB					(1 << 1)
#define CIL_RGBA				(1 << 2)
#define CIL_PFMT_SIGNED			(1 << 3)
#define CIL_PFMT_UNSIGNED		(1 << 4)
#define CIL_PFMT_NORMALIZED		(1 << 5)
#define CIL_PFMT_UNNORMALIZED	(1 << 6)
#define CIL_PFMT_BYTE			(1 << 7)
#define CIL_PFMT_SHORT			(1 << 8)
#define CIL_PFMT_INT			(1 << 9)
#define CIL_PFMT_FLOAT			(1 << 10)
#define CIL_CUBE_MAP			(1 << 11)
#define CIL_COMPRESSED			(1 << 12)
#define CIL_BPP_2				(1 << 13)
#define CIL_BPP_4				(1 << 14)
#define CIL_BPP_8				(1 << 15)
#define CIL_BMP					(1 << 16)
#define CIL_PNG					(1 << 17)
#define CIL_DDS					(1 << 18)
#define CIL_TGA					(1 << 19)
#define CIL_PVR					(1 << 20)
#define CIL_KTX					(1 << 21)
#define CIL_RAW					(1 << 22)
#define CIL_ETC1				(1 << 23)
#define CIL_ETC2				(1 << 24)
#define CIL_DXT1				(1 << 25)
#define CIL_DXT5				(1 << 26)
#define CIL_PVRTC2				(1 << 27)
#define CIL_PVRTC4				(1 << 28)
#define CIL_PVRTCII2			(1 << 29)
#define CIL_PVRTCII4			(1 << 30)

struct pvr_v3_header {
	uint32_t		version;
	uint32_t		flags;
	uint32_t		pix_format_0;
	uint32_t		pix_format_1;
	uint32_t		color_space;
	uint32_t		channel_type;
	uint32_t		height;
	uint32_t		width;
	uint32_t		depth;
	uint32_t		surfaces;
	uint32_t		faces;
	uint32_t		mipmaps_c;
	uint32_t		metadata_size;
};

struct pvr_metadata {
	unsigned char	fourcc[4];
	uint32_t		key;
	uint32_t		size;
};


struct ktx_header {
	unsigned char   identifier[12];
	uint32_t		endianess;
	uint32_t		gltype;
	uint32_t		gltypesize;
	uint32_t		glformat;
	uint32_t		glinternalformat;
	uint32_t		glbaseinternafFormat;
	uint32_t		width;
	uint32_t		height;
	uint32_t		depth;
	uint32_t		surfaces;
	uint32_t		faces;
	uint32_t		mipmaps_c;
	uint32_t		keyvaluedatasize;
};

struct DDS_PIXELFORMAT {
	unsigned int dwSize;
	unsigned int dwFlags;
	unsigned int dwFourCC;
	unsigned int dwRGBBitCount;
	unsigned int dwRBitMask;
	unsigned int dwGBitMask;
	unsigned int dwBBitMask;
	unsigned int dwABitMask;
};

struct DDS_HEADER {
	unsigned int           dwSize;
	unsigned int           dwFlags;
	unsigned int           dwHeight;
	unsigned int           dwWidth;
	unsigned int           dwPitchOrLinearSize;
	unsigned int           dwDepth;
	unsigned int           dwMipMapCount;
	unsigned int           dwReserved1[11];
	DDS_PIXELFORMAT		   ddspf;
	unsigned int           dwCaps;
	unsigned int           dwCaps2;
	unsigned int           dwCaps3;
	unsigned int           dwCaps4;
	unsigned int           dwReserved2;
};

void checkformat(ifstream &in_, unsigned int &prop) {
	std::streampos begPos = in_.tellg();

	in_.seekg(begPos);
	char	dds[4];
	in_.read((char*)dds, 3);
	dds[3] = '\0';
	if (strcmp(dds, "DDS") == 0) {
		prop |= CIL_DDS;
		in_.seekg(begPos);
		return;
	}

	in_.seekg(begPos);
	unsigned char	ktx[5];
	in_.read((char*)ktx, 4);
	ktx[0] = ' ';
	ktx[4] = '\0';
	if (strcmp((char*)ktx, " KTX") == 0) {
		prop |= CIL_KTX;
		in_.seekg(begPos);
		return;
	}

	in_.seekg(begPos);
	char pvr[4];
	in_.read((char*)&pvr, 3);
	pvr[3] = '\0';
	if (strcmp((char*)pvr, "PVR") == 0) {
		prop |= CIL_PVR;
		in_.seekg(begPos);
		return;
	}

	prop = CIL_NOT_SUPPORTED_FILE;
}

void	pvr_set_pix_format(uint32_t& pix_format, unsigned int &prop) {
	switch (pix_format) {
	case  CIL_PVRTC_2BPP_RGB_FMT: {
		prop |= CIL_PVRTC2;
		prop |= CIL_RGB;
		prop |= CIL_BPP_2;
		prop |= CIL_COMPRESSED;
	}break;
	case  CIL_PVRTC_2BPP_RGBA_FMT: {
		prop |= CIL_PVRTC2;
		prop |= CIL_RGBA;
		prop |= CIL_BPP_2;
		prop |= CIL_COMPRESSED;
	}break;
	case  CIL_PVRTC_4BPP_RGB_FMT: {
		prop |= CIL_PVRTC4;
		prop |= CIL_RGB;
		prop |= CIL_BPP_4;
		prop |= CIL_COMPRESSED;
	}break;
	case  CIL_PVRTC_4BPP_RGBA_FMT: {
		prop |= CIL_PVRTC4;
		prop |= CIL_RGBA;
		prop |= CIL_BPP_4;
		prop |= CIL_COMPRESSED;
	}break;
	case  CIL_PVRTCII_2BPP_RGB_FMT: {
		prop |= CIL_PVRTCII2;
		prop |= CIL_RGBA;
		prop |= CIL_BPP_2;
		prop |= CIL_COMPRESSED;
	}break;
	case  CIL_PVRTCII_4BPP_RGB_FMT: {
		prop |= CIL_PVRTCII4;
		prop |= CIL_RGBA;
		prop |= CIL_BPP_4;
		prop |= CIL_COMPRESSED;
	}break;
	case  CIL_ETC1_FMT: {
		prop |= CIL_ETC1;
		prop |= CIL_RGB;
		prop |= CIL_BPP_4;
		prop |= CIL_COMPRESSED;
	}break;
	case  CIL_DXT1_FMT: {
		prop |= CIL_DXT1;
		prop |= CIL_RGB;
		prop |= CIL_BPP_4;
		prop |= CIL_COMPRESSED;
	}break;
	case  CIL_DXT5_FMT: {
		prop |= CIL_DXT5;
		prop |= CIL_RGBA;
		prop |= CIL_BPP_8;
		prop |= CIL_COMPRESSED;
	}break;
	case  CIL_ETC2_FMT: {
		prop |= CIL_ETC2;
		prop |= CIL_RGBA;
		prop |= CIL_BPP_8;
		prop |= CIL_COMPRESSED;
	}break;
	}
}

void pvr_set_channel_type(uint32_t& c_type, unsigned int &prop) {
	switch (c_type) {
	case  CIL_CHT_UNSIGNED_BYTE_NORM: {
		prop |= CIL_PFMT_UNSIGNED;
		prop |= CIL_PFMT_BYTE;
		prop |= CIL_PFMT_NORMALIZED;
	}break;
	case  CIL_CHT_SIGNED_BYTE_NORM: {
		prop |= CIL_PFMT_SIGNED;
		prop |= CIL_PFMT_BYTE;
		prop |= CIL_PFMT_NORMALIZED;
	}break;
	case  CIL_CHT_UNSIGNED_BYTE: {
		prop |= CIL_PFMT_UNSIGNED;
		prop |= CIL_PFMT_BYTE;
		prop |= CIL_PFMT_UNNORMALIZED;
	}break;
	case  CIL_CHT_SIGNED_BYTE: {
		prop |= CIL_PFMT_SIGNED;
		prop |= CIL_PFMT_BYTE;
		prop |= CIL_PFMT_UNNORMALIZED;
	}break;
	case  CIL_CHT_UNSIGNED_SHORT_NORM: {
		prop |= CIL_PFMT_UNSIGNED;
		prop |= CIL_PFMT_SHORT;
		prop |= CIL_PFMT_NORMALIZED;
	}break;
	case  CIL_CHT_SIGNED_SHORT_NORM: {
		prop |= CIL_PFMT_SIGNED;
		prop |= CIL_PFMT_SHORT;
		prop |= CIL_PFMT_NORMALIZED;
	}break;
	case  CIL_CHT_UNSIGNED_SHORT: {
		prop |= CIL_PFMT_UNSIGNED;
		prop |= CIL_PFMT_SHORT;
		prop |= CIL_PFMT_UNNORMALIZED;
	}break;
	case  CIL_CHT_SIGNED_SHORT: {
		prop |= CIL_PFMT_SIGNED;
		prop |= CIL_PFMT_SHORT;
		prop |= CIL_PFMT_UNNORMALIZED;
	}break;
	case  CIL_CHT_UNSIGNED_INT_NORM: {
		prop |= CIL_PFMT_UNSIGNED;
		prop |= CIL_PFMT_INT;
		prop |= CIL_PFMT_NORMALIZED;
	}break;
	case  CIL_CHT_SIGNED_INT_NORM: {
		prop |= CIL_PFMT_SIGNED;
		prop |= CIL_PFMT_INT;
		prop |= CIL_PFMT_NORMALIZED;
	}break;
	case  CIL_CHT_UNSIGNED_INT: {
		prop |= CIL_PFMT_UNSIGNED;
		prop |= CIL_PFMT_INT;
		prop |= CIL_PFMT_UNNORMALIZED;
	}break;
	case  CIL_CHT_SIGNED_INT: {
		prop |= CIL_PFMT_SIGNED;
		prop |= CIL_PFMT_INT;
		prop |= CIL_PFMT_UNNORMALIZED;
	}break;
	case  CIL_CHT_FLOAT: {
		prop |= CIL_PFMT_FLOAT;
	}break;
	}
}

unsigned char*	load_pvr(ifstream &in_, int &x, int &y, unsigned char &mipmaps, unsigned int &prop, unsigned int &buffersize) {
	pvr_v3_header header;
	in_.seekg(0);
	in_.read((char*)&header, sizeof(pvr_v3_header));

	if (header.version == 52) {
		prop = CIL_PVR_V2_NOT_SUPPORTED;
		return 0;
	}

#if CIL_LOG_OUTPUT
	cout << "PVR Data: " << endl
		<< "Version: " << header.version << endl
		<< "Pixel format: " << header.pix_format_0 << endl
		<< "Channel type: " << header.channel_type << endl
		<< "Height: " << header.height << endl
		<< "Width: " << header.width << endl
		<< "Depth: " << header.depth << endl
		<< "Surfaces: " << header.surfaces << endl
		<< "Faces: " << header.faces << endl
		<< "Mipmap count: " << header.mipmaps_c << endl
		<< "Size meta: " << header.metadata_size << endl;
#endif

	x = header.width;
	y = header.height;
	mipmaps = header.mipmaps_c;

	if (header.faces == 6)
		prop |= CIL_CUBE_MAP;

	pvr_set_pix_format(header.pix_format_0, prop);
	pvr_set_channel_type(header.channel_type, prop);

	pvr_metadata meta;
	in_.read((char*)&meta, sizeof(pvr_metadata));

	unsigned char*	metadata = new unsigned char[meta.size + 1];
	in_.read((char*)&metadata[0], meta.size);
	metadata[meta.size] = '\0';

#if CIL_LOG_OUTPUT
	cout << "Metadata: " << endl

		<< "Fourcc 0: " << meta.fourcc[0] << endl
		<< "Fourcc 1: " << meta.fourcc[1] << endl
		<< "Fourcc 2: " << meta.fourcc[2] << endl
		<< "Fourcc 3: " << (int)meta.fourcc[3] << endl
		<< "Key: " << meta.key << endl
		<< "Data size: " << meta.size << endl;
	for (unsigned int i = 0; i < meta.size; i++) {
		cout << "Meta " << i << ": " << (int)metadata[i] << endl;
	}
#endif
	delete[] metadata;

	int currentWidth = header.width, currentHeight = header.height;
	int final_size = 0;
	int blockSize = (prop & CIL_BPP_4) ? 16 : 32;
	int bpp = (prop & CIL_BPP_4) ? 4 : 2;
	int widthBlocks = (prop & CIL_BPP_4) ? (currentWidth / 4) : (currentWidth / 8);
	int heightBlocks = currentHeight / 4;
	int current_size = 0;
	for (unsigned int i = 0; i < header.mipmaps_c; i++) {

		widthBlocks = widthBlocks < 2 ? 2 : widthBlocks;
		heightBlocks = heightBlocks < 2 ? 2 : heightBlocks;

		if (prop&CIL_ETC1) {
			current_size = (currentHeight*currentWidth*bpp) / 8;
			current_size = max(current_size, 8);
		}
		else {
			current_size = widthBlocks * heightBlocks * ((blockSize * bpp) / 8);
		}
		for (unsigned int f = 0; f < header.faces; f++) {
			final_size += current_size;
		}
		currentWidth = max(currentWidth >> 1, 1);
		currentHeight = max(currentHeight >> 1, 1);

		widthBlocks = (prop & CIL_BPP_4) ? (currentWidth / 4) : (currentWidth / 8);
		heightBlocks = currentHeight / 4;
	}

	buffersize = final_size;
	unsigned char *buffer = new unsigned char[buffersize];

	if (buffer == 0) {
		prop = CIL_NO_MEMORY;
		return 0;
	}

	in_.read((char*)&buffer[0], buffersize);

	return buffer;
}

void ktx_set_pix_format(unsigned int &format, unsigned int &prop) {

	switch (format) {
	case CIL_ETC1_RGB8_OES: {
		prop |= CIL_ETC1;
		prop |= CIL_RGB;
		prop |= CIL_BPP_4;
		prop |= CIL_COMPRESSED;
	}break;
	case CIL_COMPRESSED_RGB_PVRTC_4BPPV1_IMG: {
		prop |= CIL_PVRTC4;
		prop |= CIL_RGB;
		prop |= CIL_BPP_4;
		prop |= CIL_COMPRESSED;
	}break;
	case CIL_COMPRESSED_RGB_PVRTC_2BPPV1_IMG: {
		prop |= CIL_PVRTC2;
		prop |= CIL_RGB;
		prop |= CIL_BPP_2;
		prop |= CIL_COMPRESSED;
	}break;
	case CIL_COMPRESSED_RGBA_PVRTC_4BPPV1_IMG: {
		prop |= CIL_PVRTC4;
		prop |= CIL_RGBA;
		prop |= CIL_BPP_4;
		prop |= CIL_COMPRESSED;
	}break;
	case CIL_COMPRESSED_RGBA_PVRTC_2BPPV1_IMG: {
		prop |= CIL_PVRTC2;
		prop |= CIL_RGBA;
		prop |= CIL_BPP_2;
		prop |= CIL_COMPRESSED;
	}break;
	case CIL_COMPRESSED_RGBA_PVRTC_2BPPV2_IMG: {
		prop |= CIL_PVRTCII2;
		prop |= CIL_RGBA;
		prop |= CIL_BPP_2;
		prop |= CIL_COMPRESSED;
	}break;
	case CIL_COMPRESSED_RGBA_PVRTC_4BPPV2_IMG: {
		prop |= CIL_PVRTCII4;
		prop |= CIL_RGBA;
		prop |= CIL_BPP_4;
		prop |= CIL_COMPRESSED;
	}break;
	case CIL_COMPRESSED_RGBA8_ETC2_EAC: {
		prop |= CIL_ETC2;
		prop |= CIL_RGBA;
		prop |= CIL_BPP_8;
		prop |= CIL_COMPRESSED;
	}break;
	case CIL_COMPRESSED_RGB_S3TC_DXT1_EXT: {
		prop |= CIL_DXT1;
		prop |= CIL_RGB;
		prop |= CIL_BPP_4;
		prop |= CIL_COMPRESSED;
	}break;
	case CIL_COMPRESSED_RGBA_S3TC_DXT1_EXT: {
		prop |= CIL_DXT1;
		prop |= CIL_RGBA;
		prop |= CIL_BPP_4;
		prop |= CIL_COMPRESSED;
	}break;
	case CIL_COMPRESSED_RGBA_S3TC_DXT5_EXT: {
		prop |= CIL_DXT5;
		prop |= CIL_RGBA;
		prop |= CIL_BPP_8;
		prop |= CIL_COMPRESSED;
	}break;
	}
}

unsigned char*	load_ktx(ifstream &in_, int &x, int &y, unsigned char &mipmaps, unsigned int &prop, unsigned int &buffersize) {
	ktx_header	header;
	in_.seekg(0);
	in_.read((char*)&header, sizeof(ktx_header));

#if CIL_LOG_OUTPUT
	cout << "KTX Data: " << endl
		<< "GLType: " << header.gltype << endl
		<< "GLFormat: " << header.glformat << endl
		<< "GLInternalFormat: " << header.glinternalformat << endl
		<< "GLTypeSize: " << header.gltypesize << endl
		<< "Height: " << header.height << endl
		<< "Width: " << header.width << endl
		<< "Depth: " << header.depth << endl
		<< "Surfaces: " << header.surfaces << endl
		<< "Faces: " << header.faces << endl
		<< "Mipmap count: " << header.mipmaps_c << endl
		<< "Size Key: " << header.keyvaluedatasize << endl;
#endif
	if (header.mipmaps_c == 0)
		header.mipmaps_c = 1;

	x = header.width;
	y = header.height;
	mipmaps = header.mipmaps_c;


	if (header.faces == 6)
		prop |= CIL_CUBE_MAP;


	ktx_set_pix_format(header.glinternalformat, prop);

	if (header.keyvaluedatasize > 0) {
		unsigned char*	metadata = new unsigned char[header.keyvaluedatasize + 1];
		in_.read((char*)&metadata[0], header.keyvaluedatasize);
		metadata[header.keyvaluedatasize] = '\0';
		delete[] metadata;
	}

	streampos actual = in_.tellg();
	unsigned int totalSize = 0;
	for (unsigned int i = 0; i < header.mipmaps_c; i++) {
		unsigned int size = 0;
		in_.read((char*)&size, sizeof(unsigned int));
		size = size*header.faces;
		in_.seekg(in_.tellg() + streampos(size));
		totalSize += size;
	}


	buffersize = totalSize;

	unsigned char * pBuffer = new unsigned char[totalSize];
	unsigned char *pHead = pBuffer;
	if (pBuffer == 0) {
		prop = CIL_NO_MEMORY;
		return 0;
	}

	in_.seekg(actual);
	for (unsigned int i = 0; i < header.mipmaps_c; i++) {
		unsigned int size = 0;
		in_.read((char*)&size, sizeof(unsigned int));
		for (unsigned int f = 0; f < header.faces; f++) {
			in_.read((char*)pBuffer, size);
			pBuffer += size;
		}
	}
	pBuffer = pHead;

	return pBuffer;
}

void dds_set_pix_format(unsigned int &format,unsigned int &bppinfo,unsigned int &prop) {	
	switch (format){
		case CIL_FOURCC_RAW:{
			prop |= CIL_RAW;
			if (bppinfo == 24)
				prop |= CIL_RGB;
			else
				prop |= CIL_RGBA;
		}break;
		case CIL_FOURCC_DXT1: {
			prop |= CIL_DXT1;
			prop |= CIL_BPP_4;
			prop |= CIL_COMPRESSED;
		}break;
		case CIL_FOURCC_DXT3: {
			prop |= CIL_DXT5;
			prop |= CIL_BPP_8;
			prop |= CIL_COMPRESSED;
		}break;
		case CIL_FOURCC_DXT5: {
			prop |= CIL_DXT5;
			prop |= CIL_BPP_8;
			prop |= CIL_COMPRESSED;
		}break;
	}
}

unsigned char*	load_dds(ifstream &in_, int &x, int &y, unsigned char &mipmaps, unsigned int &prop, unsigned int &buffersize) {
	char ddstr[4];
	DDS_HEADER header;
	in_.seekg(0, std::ios::end);
	unsigned int FileSize = static_cast<unsigned int>(in_.tellg());
	in_.seekg(0, std::ios::beg);
	in_.read((char*)ddstr, 4);
	FileSize -= 4;
	in_.read((char*)&header, sizeof(DDS_HEADER));
	FileSize -= sizeof(DDS_HEADER);

	if (header.dwSize != 124) {
		in_.close();
		prop = CIL_DDS_MALFORMED;
		return 0;
	}

#if CIL_LOG_OUTPUT
	cout << "DDS Data: " << endl
		<< "	dwSize: " << header.dwSize << endl
		<< "	dwFlags: " << header.dwFlags << endl
		<< "	dwHeight: " << header.dwHeight << endl
		<< "	dwWidth: " << header.dwWidth << endl
		<< "	dwPitchOrLinearSize: " << header.dwPitchOrLinearSize << endl
		<< "	dwDepth: " << header.dwDepth << endl
		<< "	dwMipMapCount: " << header.dwMipMapCount << endl
		<< "	dwCaps: " << header.dwCaps << endl
		<< "	dwCaps2: " << header.dwCaps2 << endl
		<< "	dwCaps3: " << header.dwCaps3 << endl
		<< "	dwCaps4: " << header.dwCaps4 << endl
		<< "	dwReserved2: " << header.dwMipMapCount << endl << endl;

	cout << "DDS Pixel Format: " << endl
		<< "	dwSize: " << header.ddspf.dwSize << endl
		<< "	dwFlags: " << header.ddspf.dwFlags << endl
		<< "	dwFourCC: " << header.ddspf.dwFourCC << endl
		<< "	dwRGBBitCount: " << header.ddspf.dwRGBBitCount << endl
		<< "	dwRBitMask: " << header.ddspf.dwRBitMask << endl
		<< "	dwGBitMask: " << header.ddspf.dwGBitMask << endl
		<< "	dwBBitMask: " << header.ddspf.dwBBitMask << endl
		<< "	dwABitMask: " << header.ddspf.dwABitMask << endl;

	char *FourCC;
	FourCC = (char*)&header.ddspf.dwFourCC;
	cout << "	FOURCC: " << FourCC << endl;
#endif
	x = header.dwWidth;
	y = header.dwHeight;
	mipmaps = header.dwMipMapCount;

	if (header.dwCaps2 & CIL_DDS_CUBEMAP) {
		prop |= CIL_CUBE_MAP;
	}

	dds_set_pix_format(header.ddspf.dwFourCC, header.ddspf.dwRGBBitCount, prop);

	int numFaces = (prop&CIL_CUBE_MAP) ? 6 : 1;
	int finalSize = 0;
	int widthBlocks = x;
	int heightBlocks = y;
	int bpp = 8;
	if (prop&CIL_COMPRESSED) {
		int blockSize = (prop & CIL_BPP_4) ? 8 : 16;		
		if (prop&CIL_DXT1)
			bpp = 4;
		for (int i = 0; i < numFaces; i++) {
			widthBlocks = x;
			heightBlocks = y;
			for (int j = 0; j < mipmaps; j++) {
				int current_size = (widthBlocks*heightBlocks*bpp) / 8;
				current_size = max(current_size, blockSize);
				finalSize += current_size;
				widthBlocks >>= 1;
				heightBlocks >>= 1;
			}
		}
	}else{		
		bpp = (prop&CIL_RGB) ? 24 : 32;
		mipmaps = mipmaps == 0 ? 1 : mipmaps;
		for (int i = 0; i < numFaces; i++) {
			widthBlocks = x;
			heightBlocks = y;
			for (int j = 0; j < mipmaps; j++) {
				int current_size = (widthBlocks*heightBlocks*bpp)/8;
				finalSize += current_size;
				widthBlocks >>= 1;
				heightBlocks >>= 1;
			}
		}
	}

	buffersize = finalSize;
	FileSize -= finalSize;

	if (FileSize != 0) {
		in_.close();
		exit(666);
	}

	unsigned char *buffer = new unsigned char[buffersize];

	if (buffer == 0) {
		prop = CIL_NO_MEMORY;
		return 0;
	}

	in_.read((char*)&buffer[0], buffersize);

	return buffer;
}

void cil_free_buffer(unsigned char *pbuff) {
	delete[] pbuff;
	pbuff = 0;
}


unsigned char*	cil_load(const char* filename, int *x, int *y, unsigned char *mipmaps, unsigned int *props, unsigned int *buffersize) {

	ifstream in_(filename, ios::binary | ios::in);

	if (!in_.good()) {
		in_.close();
		*props = CIL_NOT_FOUND;
		return 0;
	}

	int x_ = 0, y_ = 0;
	unsigned int props_ = 0;
	unsigned int buffer_size_ = 0;
	unsigned char mipmaps_;
	checkformat(in_, props_);

	if (props_ == 0) {
		return 0;
	}
	else if (props_&CIL_PVR) {
		unsigned char * buffer = load_pvr(in_, x_, y_, mipmaps_, props_, buffer_size_);
		*props = props_;
		*x = x_;
		*y = y_;
		*buffersize = buffer_size_;
		*mipmaps = mipmaps_;
		in_.close();
		return buffer;
	}
	else if (props_&CIL_KTX) {
		unsigned char * buffer = load_ktx(in_, x_, y_, mipmaps_, props_, buffer_size_);
		*props = props_;
		*x = x_;
		*y = y_;
		*buffersize = buffer_size_;
		*mipmaps = mipmaps_;
		in_.close();
		return buffer;
	}else if (props_&CIL_DDS) {
		unsigned char * buffer = load_dds(in_, x_, y_, mipmaps_, props_, buffer_size_);
		*props = props_;
		*x = x_;
		*y = y_;
		*buffersize = buffer_size_;
		*mipmaps = mipmaps_;
		in_.close();
		return buffer;
	}

	return 0;
}


#endif