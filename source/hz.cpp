#include "hz.h"
#include "Core/Base.h"
#include "optick.h"

#if OPTICK_MSVC
#pragma warning( push )

//C4250. inherits 'std::basic_ostream'
#pragma warning( disable : 4250 )

//C4127. Conditional expression is constant
#pragma warning( disable : 4127 )
#endif


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
		//OPTICK_FRAME("MainThread");
		CEngine::RunTime();
	}

	CEngine::Shutdown();

	return 0;
}

void CEngine::StartUp()
{
	OPTICK_APP("HZ");
	// Setting memory allocators
	//OPTICK_SET_MEMORY_ALLOCATOR(
	//	[](size_t size) -> void* { return operator new(size); },
	//	[](void* p) { operator delete(p); },
	//	[]() { /* Do some TLS initialization here if needed */ }
	//);
	//
	//OPTICK_APP("HZ");

	for (CBaseSystem* system : BaseSystems)
	{
		if (system->Init() == false)
		{
			HZ_CORE_ASSERT("Failed to start system: {0}", system->GetName());
		}
	}
}

void CEngine::RunTime()
{
	//OPTICK_EVENT();
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
		{
			HZ_CORE_ASSERT("Failed to shutdown system: %s", system->GetName());
		}
	}
}
