#pragma once
#include <spdlog/spdlog.h>
#include <Core/Base.h>
#include <Core/BaseSystem.h>

namespace HZ
{
	class CLog : public CBaseSystem
	{
	public:
		CLog();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

		bool Init() override;

	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define HZ_CORE_TRACE(...)    ::HZ::CLog::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)     ::HZ::CLog::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)     ::HZ::CLog::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)    ::HZ::CLog::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_CRITICAL(...) ::HZ::CLog::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros				
#define HZ_TRACE(...)         ::HZ::CLog::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)          ::HZ::CLog::GetClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)          ::HZ::CLog::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...)         ::HZ::CLog::GetClientLogger()->error(__VA_ARGS__)
#define HZ_CRITICAL(...)      ::HZ::CLog::GetClientLogger()->critical(__VA_ARGS__)