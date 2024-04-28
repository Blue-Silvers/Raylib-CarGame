#include "LoadAllTextureAtStart.h"
LoadAllTextureAtStart::LoadAllTextureAtStart()
{

}
void LoadAllTextureAtStart::Start()
{
	//load texture
		loadGrass = LoadTexture("kenney_racing-pack/PNG/Tiles/Grass/land_grass04.png");

		loadRoad = LoadTexture("kenney_racing-pack/PNG/Tiles/Asphalt_road/road_asphalt22.png");

		loadCheckpoint = LoadTexture("kenney_racing-pack/PNG/Tiles/Asphalt_road/road_asphalt90.png");

		loadStartLine1 = LoadTexture("kenney_racing-pack/PNG/Tiles/Asphalt_road/road_asphalt87.png");

		loadStartLine2 = LoadTexture("kenney_racing-pack/PNG/Tiles/Asphalt_road/road_asphalt89.png");

		loadStartPos = LoadTexture("kenney_racing-pack/PNG/Tiles/Asphalt_road/road_asphalt84.png");

		loadObstacle = LoadTexture("kenney_racing-pack/PNG/Objects/tree_small.png");

		loadTribune = LoadTexture("kenney_racing-pack/PNG/Objects/tribune_full.png");
}