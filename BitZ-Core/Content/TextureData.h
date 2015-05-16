#pragma once

namespace Bitz
{
	namespace GFX
	{
		class Texture;
		class GraphicsManager;
		class RenderEngine;
	}

	namespace Content
	{
		class ContentManager;

		class TextureData
		{
			friend GFX::GraphicsManager;
			friend GFX::RenderEngine;
			friend ContentManager;
			friend GFX::Texture;

		public:
			TextureData();
			~TextureData();

			uint32_t GetWidth() const;
			uint32_t GetHeight() const;
			uint32_t GetID() const;

		protected:
			/// <summary>
			/// Loads the PNG at the provided fileName returning a TextureData
			/// </summary>
			/// <param name='fileName'>The filename to load relative to ContentManager::GetGraphicsRoot()</param>
			static TextureData * Load(const std::wstring fileName);
			static std::vector<TextureData *> _LoadedTextureData;

			uint32_t GetOpenglTextureID() const;
			void SetOpenglTextureID(uint32_t newID);

			void IncrementUsageCount();
			void DecrementUsageCount();

			uint32_t _OpenglTextureID = -1;

		private:
			uint8_t * _PixelData;
			uint32_t _Width = 0;
			uint32_t _Height = 0;
			uint32_t _ID = -1;
			uint32_t _UsageCount = 0;

			static uint32_t _NextID;
		};
	}
}
