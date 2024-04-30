
#include "paint.h"
#include "SerializableShapes.h"
int WinMain()
{
	Paint paint;

	while (paint.running())
	{
		paint.update();
		paint.render();
	}

	return 0;
}