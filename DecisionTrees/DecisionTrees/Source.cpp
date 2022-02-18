#include "Node.h"
#include <iostream>
#include <thread>
using namespace std::chrono_literals;

int root_node_random()
{
	int random = rand() % 100;
	if (random < 40)
	{
		return 0;
	}
	else if (random >= 40 && random <= 90)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

int leaf_node_one()
{
	std::cout << "Leaf node 1 has been called." << std::endl;
	return 0;
}

int leaf_node_two()
{
	std::cout << "Leaf node 2 has been called." << std::endl;
	return 0;
}

int leaf_node_three()
{
	std::cout << "Leaf node 3 has been called." << std::endl;
	return 0;
}

int main()
{
	srand(time(NULL));

	// Create functions / lambdas for each unique node in the tree
	int n = root_node_random();
	leaf_node_one();

	// Create instances of deciusion nodes and leaf nodes as appropriate
	DecisionNode root_node(root_node_random);
	Node leaf1(leaf_node_one);
	Node leaf2(leaf_node_two);
	Node leaf3(leaf_node_three);
	// Add the leaf nodes as children to the connected decision nodes
	root_node.addChildNode(&leaf1);
	root_node.addChildNode(&leaf2);
	root_node.addChildNode(&leaf3);
	// Run the root node of the tree
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		root_node.run();
	}
}