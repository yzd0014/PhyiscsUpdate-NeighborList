#pragma once
#include <vector>

#define x_ii 0
#define y_ii 1
#define z_ii 2
#define lengthCell 2
#define EMPTY -1

namespace eae6320 {
	namespace GameCommon {
		class GameObject;
	}

	class NeighborList {
	public:
		NeighborList(std::vector<GameCommon::GameObject *> & i_allGameObjects);

		int numCells[3];            	/* Number of cells in the x|y|z direction */
		int numCellsXZ;					/* Total number of cells in YZ plane */
		int numCellsXYZ;				/* Total number of cells in XYZ area*/
		int head[1200];    			/* Headers for the linked cell lists */
		int linkedCellist[100];
	};
}
