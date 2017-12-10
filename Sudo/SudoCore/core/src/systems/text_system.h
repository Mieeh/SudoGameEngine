#pragma once

#include"sudo_system.h"

#include<vector>
#include<map>

#include<ft2build.h>
#include FT_FREETYPE_H

#include"../graphics/text_label.h"
#include"../graphics/text_character.h"

// Forward declerations
namespace sudo {
	namespace math {
		class Vector2;
		class Color;
	}
	namespace graphics {
		class Shader;
	}
}

namespace sudo { namespace sudo_system { 

	class Font;

	class TextSystem : SudoSystem {
	private:
		// Private constructor since this is a singleton class
		TextSystem() { }

		// Static instance of class (only instance)
		static TextSystem *_instance;

	public:
		static TextSystem *Instance();

		// Methods from the SudoSystem base class 
		void Update() override;
		void Start() override;
		void Enable() override;
		void Disable() override;
		void CleanUp() override;

		// Render routines
		void Flush();

		// Method called by user 
		void DrawText(std::string a_string, math::Vector2 a_position, math::Color a_color);
		void LoadFont(const char* a_path, int a_index);
		void SetFont(int a_index);	
	
	private:
		std::map<char, graphics::GlyphCharacter> m_characters;
		std::vector<graphics::TextLabel> m_textToRender;
		graphics::Shader *m_shader;

		unsigned int VAO, VBO;

		// FreeType members
		FT_Library m_ftLib;
		FT_Face m_ftFace;
		std::map<int, Font*> m_fonts;
	};

} } 