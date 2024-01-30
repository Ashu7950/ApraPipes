#pragma once

#include "Module.h"
#include <gtk/gtk.h>// remove this 
#include <boost/serialization/vector.hpp>
class GtkGlRendererProps : public ModuleProps
{
public:
	GtkGlRendererProps(GtkWidget* _glArea, int _windowWidth, int _windowHeight) : ModuleProps() // take gtk string 
	{
		// gladeFileName = _gladeFileName;
		glArea = _glArea;
		windowWidth = _windowWidth;
		windowHeight = _windowHeight;
	}
	GtkWidget* glArea;
	int windowWidth = 0;
	int windowHeight = 0;
};

class GtkGlRenderer : public Module
{
public:
    GtkGlRenderer(GtkGlRendererProps props);
    ~GtkGlRenderer();

    bool init();
    bool term();
	bool changeProps(GtkWidget* glArea, int windowWidth, int windowHeight);
	// wait_for_exit

protected:
	bool process(frame_container& frames);
	bool processSOS(frame_sp &frame);
	bool validateInputPins();
	bool shouldTriggerSOS();
	bool handleCommand(Command::CommandType type, frame_sp &frame);
private:
	class Detail;
	boost::shared_ptr<Detail> mDetail;
};
