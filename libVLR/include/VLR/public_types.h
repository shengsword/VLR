﻿#pragma once

#if defined(__cplusplus)
#include <cstdint>
#else
#include <stdbool.h>
#include <stdint.h>
#endif

enum VLRSpectrumType {
    VLRSpectrumType_Reflectance = 0,
    VLRSpectrumType_Transmittance = VLRSpectrumType_Reflectance,
    VLRSpectrumType_LightSource,
    VLRSpectrumType_IndexOfRefraction,
    VLRSpectrumType_NA,
    NumVLRSpectrumTypes
};

enum VLRColorSpace {
    VLRColorSpace_Rec709_D65_sRGBGamma = 0,
    VLRColorSpace_Rec709_D65,
    VLRColorSpace_XYZ,
    VLRColorSpace_xyY,
    NumVLRColorSpaces
};



enum VLRDataFormat {
    VLRDataFormat_RGB8x3 = 0,
    VLRDataFormat_RGB_8x4,
    VLRDataFormat_RGBA8x4,
    VLRDataFormat_RGBA16Fx4,
    VLRDataFormat_RGBA32Fx4,
    VLRDataFormat_RG32Fx2,
    VLRDataFormat_Gray32F,
    VLRDataFormat_Gray8,
    VLRDataFormat_GrayA8x2,
    VLRDataFormat_BC1,
    VLRDataFormat_BC2,
    VLRDataFormat_BC3,
    VLRDataFormat_BC4,
    VLRDataFormat_BC4_Signed,
    VLRDataFormat_BC5,
    VLRDataFormat_BC5_Signed,
    VLRDataFormat_BC6H,
    VLRDataFormat_BC6H_Signed,
    VLRDataFormat_BC7,
    NumVLRDataFormats
};



enum VLRParameterFormFlag {
    VLRParameterFormFlag_ImmediateValue = 1 << 0,
    VLRParameterFormFlag_Node = 1 << 1,
    VLRParameterFormFlag_Both = (VLRParameterFormFlag_ImmediateValue | VLRParameterFormFlag_Node)
};



enum VLRShaderNodePlugType {
    VLRShaderNodePlugType_float1 = 0,
    VLRShaderNodePlugType_float2,
    VLRShaderNodePlugType_float3,
    VLRShaderNodePlugType_float4,
    VLRShaderNodePlugType_Point3D,
    VLRShaderNodePlugType_Vector3D,
    VLRShaderNodePlugType_Normal3D,
    VLRShaderNodePlugType_Spectrum,
    VLRShaderNodePlugType_Alpha,
    VLRShaderNodePlugType_TextureCoordinates,
    NumVLRShaderNodePlugTypes
};

struct VLRShaderNodePlug {
    uintptr_t nodeRef;
    uint32_t info;
};



enum VLRTangentType {
    VLRTangentType_TC0Direction = 0,
    VLRTangentType_RadialX,
    VLRTangentType_RadialY,
    VLRTangentType_RadialZ,
};



enum VLRTransformType {
    VLRTransformType_Static = 0,
};

enum VLRNodeType {
    VLRNodeType_TriangleMeshSurfaceNode = 0,
    VLRNodeType_InternalNode,
};

enum VLRDebugRenderingMode {
    VLRDebugRenderingMode_BaseColor = 0,
    VLRDebugRenderingMode_GeometricNormal,
    VLRDebugRenderingMode_ShadingTangent,
    VLRDebugRenderingMode_ShadingBitangent,
    VLRDebugRenderingMode_ShadingNormal,
    VLRDebugRenderingMode_TC0Direction,
    VLRDebugRenderingMode_TextureCoordinates,
    VLRDebugRenderingMode_GeometricVsShadingNormal,
    VLRDebugRenderingMode_ShadingFrameLengths,
    VLRDebugRenderingMode_ShadingFrameOrthogonality,
};

#if !defined(__cplusplus)
typedef enum VLRSpectrumType VLRSpectrumType;
typedef enum VLRColorSpace VLRColorSpace;
typedef enum VLRDataFormat VLRDataFormat;
typedef enum VLRParameterFormFlag VLRParameterFormFlag;
typedef enum VLRShaderNodePlugType VLRShaderNodePlugType;
typedef struct VLRShaderNodePlug VLRShaderNodePlug;
typedef enum VLRTangentType VLRTangentType;
typedef enum VLRTransformType VLRTransformType;
typedef enum VLRNodeType VLRNodeType;
typedef enum VLRDebugRenderingMode VLRDebugRenderingMode;
#endif



struct VLRImmediateSpectrum {
    const char* colorSpace;
    float e0;
    float e1;
    float e2;
};

struct VLRPoint3D {
    float x, y, z;
};

struct VLRNormal3D {
    float x, y, z;
};

struct VLRVector3D {
    float x, y, z;
};

struct VLRTexCoord2D {
    float u, v;
};

struct VLRQuaternion {
    float x, y, z, w;
};

#if !defined(__cplusplus)
typedef struct VLRImmediateSpectrum VLRImmediateSpectrum;
typedef struct VLRPoint3D VLRPoint3D;
typedef struct VLRNormal3D VLRNormal3D;
typedef struct VLRVector3D VLRVector3D;
typedef struct VLRTexCoord2D VLRTexCoord2D;
typedef struct VLRQuaternion VLRQuaternion;
#endif



struct VLRVertex {
    VLRPoint3D position;
    VLRNormal3D normal;
    VLRVector3D tc0Direction;
    VLRTexCoord2D texCoord;
};

#if !defined(__cplusplus)
typedef struct VLRVertex VLRVertex;
#endif



#define VLR_PROCESS_CLASS_LIST() \
    VLR_PROCESS_CLASS(Object); \
\
    VLR_PROCESS_CLASS(ParameterInfo); \
\
    VLR_PROCESS_CLASS(Connectable); \
\
    VLR_PROCESS_CLASS(Image2D); \
    VLR_PROCESS_CLASS(LinearImage2D); \
    VLR_PROCESS_CLASS(BlockCompressedImage2D); \
\
    VLR_PROCESS_CLASS(ShaderNode); \
\
    VLR_PROCESS_CLASS(SurfaceMaterial); \
\
    VLR_PROCESS_CLASS(Transform); \
    VLR_PROCESS_CLASS(StaticTransform); \
\
    VLR_PROCESS_CLASS(Node); \
    VLR_PROCESS_CLASS(SurfaceNode); \
    VLR_PROCESS_CLASS(TriangleMeshSurfaceNode); \
    VLR_PROCESS_CLASS(InternalNode); \
    VLR_PROCESS_CLASS(Scene); \
\
    VLR_PROCESS_CLASS(Camera);
