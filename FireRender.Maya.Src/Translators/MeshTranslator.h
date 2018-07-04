#pragma once

#include "frWrap.h"
#include "FireRenderUtils.h"

#include <maya/MItMeshPolygon.h>
#include <maya/MObject.h>
#include <vector>

namespace FireMaya
{
	namespace MeshTranslator
	{
	//public:	
		std::vector<frw::Shape> TranslateMesh(frw::Context context, const MObject& originalObject);

	//private:
		MObject GenerateSmoothMesh(const MObject& object, const MObject& parent, MStatus& status);

		/** Tessellate a NURBS surface and return the resulting mesh object. */
		MObject TessellateNurbsSurface(const MObject& object, const MObject& parent, MStatus& status);

		MObject GetTesselatedObjectIfNecessary(const MObject& originalObject, MStatus& mstatus);

		void GetUVCoords(const MFnMesh& fnMesh,
			MStringArray& uvSetNames,
			std::vector<std::vector<Float2> >& uvCoords,
			std::vector<const float*>& puvCoords,
			std::vector<size_t>& sizeCoords);

		void AddPolygon(MItMeshPolygon& it,
			const MStringArray& uvSetNames,
			std::vector<int>& vertexIndices,
			std::vector<int>& normalIndices,
			std::vector<std::vector<int> >& uvIndices);
	};
}
