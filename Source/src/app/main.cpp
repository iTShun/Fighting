#include <cstdio>
#include <SDL.h>
#include <SDL_syswm.h>
#ifdef _WIN32
#	include <windows.h>
#endif
#include "platform/Platform.h"

NS_BEGIN

static const int const s_width = 960;
static const int const s_height = 640;

class Application
{
public:
	Application()
	: m_window(nullptr)
	, m_finished(false)
	, m_window_mode(true)
	, m_exit_code(0)
	{
		Assert(!s_instance);
		s_instance = this;
	}

	~Application()
	{
		s_instance = nullptr;
	}

	void setup()
	{
		char current_dir[MAX_PATH_LENGTH];
#ifdef _WIN32
		GetCurrentDirectoryA(sizeof(current_dir), current_dir);
#else
		current_dir[0] = '\0';
#endif

		u32 flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI;
		if (!m_window_mode) flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;



		m_window = SDL_CreateWindow("Game App", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, s_width, s_height, flags);
		if (!m_window_mode) SDL_SetWindowFullscreen(m_window, SDL_WINDOW_FULLSCREEN_DESKTOP);

		
	}

	void shutdown()
	{

	}

	void handleEvents()
	{

	}

	void frame()
	{

		handleEvents();
	}

	int run()
	{
		setup();

		while (!m_finished)
		{
			frame();
		}

		return m_exit_code;
	}
	
	void exit(int exit_code)
	{
		m_finished = true;
		m_exit_code = exit_code;
	}

	inline int getExitCode() const { return m_exit_code; }

	inline bool isFinished() const { return m_finished; }

	static void outputToVS(const char* system, const char* message)
	{
#ifdef _MSC_VER
		/*char tmp[2048];
		copyString(tmp, system);
		catString(tmp, " : ");
		catString(tmp, message);
		catString(tmp, "\r");

		OutputDebugString(tmp);*/
#endif
	}

	static void outputToConsole(const char* system, const char* message)
	{
		printf("%s: %s\n", system, message);
	}

protected:
	static Application* s_instance;
	SDL_Window* m_window;
	bool m_finished;
	bool m_window_mode;
	int m_exit_code;
};

Application* Application::s_instance = nullptr;

NS_END

#ifdef _WIN32
INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
#else
int main(int args, char* argv[])
#endif
{
	NS_::Application app;
	return app.run();
}
