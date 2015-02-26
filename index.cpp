#include "index.h"

// namespace data_lvl
// {
	float data_lvl::SurfaceGeopotential(float z,float g)
	{
		return g*z ;
	}
	float data_lvl::TempReductionFactor(float Gg, float Rd, float g)
	{
		return Gg*Rd/g;
	}
// };