#include "hz.h"
#include "Core/Base.h"

bool CEngine::m_ShutDown;

std::vector<CBaseSystem*> BaseSystems =
{
	new HZ::CLog(),
};

int main()
{
	CEngine::StartUp();
	
	while (!CEngine::m_ShutDown)
	{
		CEngine::RunTime();
	}

	CEngine::Shutdown();

	return 0;
}

void CEngine::StartUp()
{
	for (CBaseSystem* system : BaseSystems)
	{
		if(system->Init() == false)
			HZ_CORE_ASSERT("Failed to start system: {0}", system->GetName());
	}
}

void CEngine::RunTime()
{
	for (CBaseSystem* system : BaseSystems)
	{
		system->RunTime();
	}
}

void CEngine::Shutdown()
{
	for (CBaseSystem* system : BaseSystems)
	{
		if (system->Shutdown() == false)
			HZ_CORE_ASSERT("Failed to shutdown system: %s", system->GetName());
	}
}
