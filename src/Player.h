#pragma once
#include "Agent.h"
#include <vector>
#include <stdlib.h>
#include <ctime>

class Player {

	public:
		Player();
		void addAgent();
		Agent* getAgent(int index);
		int getAgentCount();

	private:
		std::vector<Agent*> agents;
};
