#include "GlutInitializer.h"
#include "Ejik.h"

void Draw()
{
	auto character = Ejik();
	character.Draw(200, 200);
}

// Driver Code
int main(int argc, char** argv)
{
	GlutInitializer glutInit = GlutInitializer(argc, argv, Draw);
	return 0;
}