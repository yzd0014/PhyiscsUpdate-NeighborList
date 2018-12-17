--[[
	This file lists every asset that must be built by the AssetBuildSystem
]]

return
{
	shaders =
	{
		{ path = "Shaders/Vertex/vertexInputLayout.shader", arguments = { "vertex" } },
	},
	meshes = {
		"Meshes/cube.mesh",
		"Meshes/plane.mesh",
		"Meshes/ceiling.mesh",
		"Meshes/gun.mesh",
		"Meshes/bullet.mesh",
		"Meshes/outline.mesh",
		"Meshes/front_back_wall.mesh",
		"Meshes/missile.mesh",
		"Meshes/boss.mesh",
	},
	effects = {
		"Effects/white.effect",
		"Effects/red.effect",
		"Effects/blue.effect",
		"Effects/white_front_light.effect",
		"Effects/white_back_light.effect",
	},
}
