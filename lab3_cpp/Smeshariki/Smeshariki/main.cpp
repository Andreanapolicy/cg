#include "GlutInitializer.h"
#include "Ejik.h"

void Draw()
{
	auto character = Ejik();
	character.Draw(100, 100);
}

// Driver Code
int main(int argc, char** argv)
{
	GlutInitializer glutInit = GlutInitializer(argc, argv, Draw);
	return 0;
}