#pragma once

class CEngine 
{
public:
	static void StartUp();
	static void RunTime();
	static void Shutdown();

	static bool m_ShutDown;
};
