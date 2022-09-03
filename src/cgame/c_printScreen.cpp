using namespace Campaign;

void printScreen()
{
	for (const auto &i : HUD)
		std::cout << i;
	playr = std::make_unique<Playr>();
	playr->cmd_prompt();
}