#include "NeighborList.h"
#include "Engine/GameCommon/GameObject.h"

#define xOffset 5
#define yOffset 1
#define zOffset 10
eae6320::NeighborList::NeighborList(std::vector<GameCommon::GameObject *> & i_allGameObjects) {
	numCells[x_ii] = 10;
	numCells[y_ii] = 6;
	numCells[z_ii] = 20;

	/* Make a linked-cell list --------------------------------------------*/
	
	numCellsXZ = numCells[x_ii] * numCells[z_ii];
	numCellsXYZ = numCellsXZ * numCells[y_ii];

	// Reset the headers, head
	for (int c = 0; c < numCellsXYZ; c++)
	{
		head[c] = EMPTY;
	}

	size_t numOfGameObjects = i_allGameObjects.size();
	for (size_t i = 6; i < numOfGameObjects; i++) {
		int vectorCells[3];
		if (i_allGameObjects[i]->m_State.position.x < 0) {
			vectorCells[x_ii] = (int)(i_allGameObjects[i]->m_State.position.x / lengthCell) - 1 + xOffset;
		}
		else {
			vectorCells[x_ii] = (int)(i_allGameObjects[i]->m_State.position.x / lengthCell) + xOffset;
		}
		
		if (i_allGameObjects[i]->m_State.position.y < 0) {
			vectorCells[y_ii] = (int)(i_allGameObjects[i]->m_State.position.y / lengthCell - 1) + yOffset;
		}
		else {
			vectorCells[y_ii] = (int)(i_allGameObjects[i]->m_State.position.y / lengthCell) + yOffset;
		}

		if (i_allGameObjects[i]->m_State.position.z < 0) {
			vectorCells[z_ii] = (int)(i_allGameObjects[i]->m_State.position.z / lengthCell - 1) + zOffset;
		}
		else {
			vectorCells[z_ii] = (int)(i_allGameObjects[i]->m_State.position.z / lengthCell) + zOffset;
		}
		
		int c = numCellsXZ * vectorCells[y_ii] + numCells[x_ii] * vectorCells[z_ii] + vectorCells[x_ii];

		linkedCellist[i] = head[c];
		head[c] = (int)i;
	}
}