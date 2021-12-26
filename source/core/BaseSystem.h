#pragma once

#include <memory>

class CBaseSystem
{
public:
	virtual bool Init();
	virtual bool RunTime();
	virtual bool Shutdown();

	const char* GetName() const { return m_Name; }

protected:
	const char* m_Name;

};
