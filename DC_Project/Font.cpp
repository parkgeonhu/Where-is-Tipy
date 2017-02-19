#include "Font.h"

extern LPDIRECT3DDEVICE9 g_pd3dDevice;
extern LPD3DXSPRITE g_pSprite;

Font::Font(string family, int type, int size)
{
	text = "";
	size = size;
	color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	if (type == 0)
	{
		D3DXCreateFontA(
			g_pd3dDevice,
			size, size / 2 - size / 10,
			FW_LIGHT,
			D3DX_DEFAULT,
			NULL,
			DEFAULT_CHARSET,
			NULL,
			ANTIALIASED_QUALITY,
			NULL, family.c_str(), &font);
	}

	else if (type == 1)
	{
		D3DXCreateFontA(
			g_pd3dDevice,
			size, size / 2 - size / 10,
			FW_MEDIUM,
			D3DX_DEFAULT,
			NULL,
			DEFAULT_CHARSET,
			NULL,
			ANTIALIASED_QUALITY,
			NULL, family.c_str(), &font);
	}

	else if (type == 2)
	{
		D3DXCreateFontA(
			g_pd3dDevice,
			size, size / 2 - size / 10,
			FW_BOLD,
			D3DX_DEFAULT,
			NULL,
			DEFAULT_CHARSET,
			NULL,
			ANTIALIASED_QUALITY,
			NULL, family.c_str(), &font);
	}

	else
	{
		D3DXCreateFontA(
			g_pd3dDevice,
			size, size / 2 - size / 10,
			FW_LIGHT,
			D3DX_DEFAULT,
			NULL,
			DEFAULT_CHARSET,
			NULL,
			ANTIALIASED_QUALITY,
			NULL, family.c_str(), &font);
	}
}

Font::~Font()
{
	font->Release();
}

void Font::Update(float eTime)
{
}

void Font::Render()
{
	IObject::Render(&mat);

	g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	g_pSprite->SetTransform(&mat);

	font->DrawTextA(g_pSprite, text.data(), -1, NULL, DT_TOP | DT_LEFT, color);

	g_pSprite->End();
}

void Font::SetText(LPCSTR fmt, ...)
{
	char   buff[1024] = { 0, };

	vsprintf(buff, fmt, (char*)(&fmt + 1));

	text = buff;
}