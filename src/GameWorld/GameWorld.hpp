#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>
#include <random>

#include "WorldBase.hpp"
#include "utils.hpp"

enum class FunctionName
{
	None,
	PlantSunflower,
	PlantPea,
	PlantWallnut,
	PlantCherry,
	PlantRepeater,
	Spade,
};

#include "GameObject.hpp"


class GameObject;
using pGameObject = std::shared_ptr<GameObject>;


class GameWorld : public WorldBase, public std::enable_shared_from_this<GameWorld> {
public:
  // Use shared_from_this() instead of "this".
	static inline int const SunStartCount = 180;
	static inline int const SunCountInterval = 300;
	static inline int const InitSun = 50;
	static inline int const InitWave = 50;
	static inline int const ZombieStartCount = 120;

  GameWorld();
  virtual ~GameWorld();

  void Init() override;

  LevelStatus Update() override;

  void CleanUp() override;

  void AddObject(pGameObject object) { m_objects.emplace_front(object); };

  FunctionName GetFunction() { return m_function; };
  void SetFunction(FunctionName functionname) { m_function = functionname; };

  bool existZombie(int y) { return true; };

private: 

	std::list<pGameObject> m_objects{};
	unsigned int m_SunCountDown{ SunStartCount };
	unsigned int m_ZombieCountDown{ ZombieStartCount };
	int m_Wave{ InitWave };
	FunctionName m_function{ FunctionName::None };
};

#endif // !GAMEWORLD_HPP__
