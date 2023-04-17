cmake_minimum_required( VERSION 3.25.1 )

project( dxlib
        VERSION 0.0.0
	LANGUAGES CXX )

set( SOURCE main.cpp )
set( OUTPUT main )
set( DX_DIR ${PROJECT_SOURCE_DIR}/dxlib )

add_executable( ${OUTPUT} WIN32 ${SOURCE} )

target_include_directories( ${OUTPUT} PUBLIC ${DX_DIR} )
target_link_directories( ${OUTPUT} PUBLIC ${DX_DIR} )
target_compile_options( ${OUTPUT} PUBLIC
	-DDX_GCC_COMPILE
)

target_link_libraries( ${OUTPUT} PUBLIC
	DxLib
	DxUseCLib
	DxDrawFunc
	jpeg
	png
	zlib
	tiff
	theora_static
	vorbis_static
	vorbisfile_static
	ogg_static
	bulletdynamics
	bulletcollision
	bulletmath
	opusfile
	opus
	silk_common
	celt
)
