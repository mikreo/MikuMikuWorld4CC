#pragma once
#include <string>
#include "json.hpp"
#include "Math.h"

namespace MikuMikuWorld
{
	class ApplicationConfiguration
	{
	private:
		bool keyExists(const nlohmann::json&, const char* key);
		int tryGetInt(const nlohmann::json&, const char* key, int def);
		float tryGetFloat(const nlohmann::json&, const char* key, float def);
		bool tryGetBool(const nlohmann::json&, const char* key, bool def);
		Vector2 tryGetVector2(const nlohmann::json&, const char* key);
		Color tryGetColor(const nlohmann::json&, const char* key);
		std::string tryGetString(const nlohmann::json&, const char* key);

	public:
		std::string version;
		Vector2 windowPos;
		Vector2 windowSize;
		bool maximized;
		bool vsync;
		int accentColor;
		Color userColor;

		int timelineWidth;
		int notesHeight;
		int division;
		float zoom;
		bool useSmoothScrolling;
		float smoothScrollingTime;

		ApplicationConfiguration();

		void read(const std::string& filename);
		void write(const std::string& filename);
		void restoreDefault();
	};
}