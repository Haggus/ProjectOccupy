#pragma once
#include "Agent.h"
#include <vector>

class Player {

	public:
		Player();
		void addAgent();
		Agent* getAgent(int index);
		int getAgentCount();
		
	private:
		std::vector<Agent*> agents;
};