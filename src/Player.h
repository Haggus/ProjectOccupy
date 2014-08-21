#pragma once

class Player {

	public:
		Player();
		void addAgent();
		void removeAgent();
		int getAgentCount();
		int getAgentMax();
		int getActivity(int number);

	private:
		int agents;
		int agentsMax;
		int activities[4];
};
