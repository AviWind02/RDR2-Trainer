#include "pch.h"
#include "feature/local/localfeatures.h"

void renderUI()//This is the title and footer. 
{
	base::GUI::Title();
	//base::view::MainMenuView();//Main Menu View
	base::view::SelfView();
	base::GUI::End();
}

void ScriptMain()
{
	srand(GetTickCount());
	while (true)
	{
		base::GUI::controls::ControlTick();
		renderUI();
		feature::self::tick();
		WAIT(0);

	}
}