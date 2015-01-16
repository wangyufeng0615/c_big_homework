//ÍË³ö
#include "Header.h"

static MOUSEMSG m;

void exit_button()
{
	m = GetMouseMsg();
	if (m.uMsg == WM_LBUTTONDOWN)
	{
		if (m.x >= 360 && m.x <= 480 && m.y >= 40 && m.y <= 100)
		{
			exit(0);
		}
	}
	return;
}
