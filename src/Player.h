#pragma once

class Player {

	public:
		Player();
		void addAgent();
		bool removeAgent();
		int getAgentCount();
		int getAgentMax();

	private:
		int agents;
		int agentsMax;
};
