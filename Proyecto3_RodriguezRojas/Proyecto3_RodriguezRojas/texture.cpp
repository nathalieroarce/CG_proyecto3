#include "pch.h"
#include "imager.h"
#include "string.h"

CString ModuleDirectory, ErrorLog;

namespace Imager
{
	/*
	CTexture::CTexture()
	{
		Data = NULL;
		Width = Height = 0;
	}

	CTexture::~CTexture()
	{

	}

	bool CTexture::CreateTexture2D(const char *Texture2DFileName)
	{
		CString FileName = ModuleDirectory + Texture2DFileName;
		CString ErrorText = "Error loading file " + FileName + "! -> ";

		FREE_IMAGE_FORMAT fif = FreeImage_GetFileType(FileName);

		if (fif == FIF_UNKNOWN)
		{
			fif = FreeImage_GetFIFFromFilename(FileName);
		}

		if (fif == FIF_UNKNOWN)
		{
			ErrorLog.Append(ErrorText + "fif is FIF_UNKNOWN" + "\r\n");
			return false;
		}

		FIBITMAP *dib = NULL;

		if (FreeImage_FIFSupportsReading(fif))
		{
			dib = FreeImage_Load(fif, FileName);
		}

		if (dib == NULL)
		{
			ErrorLog.Append(ErrorText + "dib is NULL" + "\r\n");
			return false;
		}

		int Width = FreeImage_GetWidth(dib);
		int Height = FreeImage_GetHeight(dib);
		int Pitch = FreeImage_GetPitch(dib);
		int BPP = FreeImage_GetBPP(dib);

		if (Width == 0 || Height == 0)
		{
			ErrorLog.Append(ErrorText + "Width or Height is 0" + "\r\n");
			return false;
		}

		BYTE *Bits = FreeImage_GetBits(dib);

		if (Bits == NULL)
		{
			ErrorLog.Append(ErrorText + "Bits is NULL" + "\r\n");
			return false;
		}

		if (BPP != 24 && BPP != 32)
		{
			FreeImage_Unload(dib);
			ErrorLog.Append(ErrorText + "BPP is not 24 nor 32" + "\r\n");
			return false;
		}

		Destroy();

		Data = new BYTE[Width * Height * 3];

		this->Width = Width;
		this->Height = Height;

		int bpp = BPP / 8;

		BYTE *data = Data, *line = Bits;

		for (int y = 0; y < Height; y++)
		{
			BYTE *pixel = line;

			for (int x = 0; x < Width; x++)
			{
				data[0] = pixel[2];
				data[1] = pixel[1];
				data[2] = pixel[0];

				pixel += bpp;
				data += 3;
			}

			line += Pitch;
		}

		FreeImage_Unload(dib);

		return true;
	}

	float OD255 = 1.0f / 255;

	Color CTexture::GetColorNearest(float s, float t)
	{
		Color  c;

		if (Data != NULL)
		{
			s -= (int)s;
			t -= (int)t;

			if (s < 0.0f) s += 1.0f;
			if (t < 0.0f) t += 1.0f;

			int x = (int)(s * Width), y = (int)(t * Height);

			BYTE *data = (Width * y + x) * 3 + Data;

			c = Color(OD255 * data[0], OD255 * data[1], OD255 * data[2]);
		}

		return c;
	}

	Color CTexture::GetColorBilinear(float s, float t)
	{
		Color color;

		if (Data != NULL)
		{
			s -= (int)s;
			t -= (int)t;

			if (s < 0.0f) s += 1.0f;
			if (t < 0.0f) t += 1.0f;

			float dx = s * Width - 0.5f, dy = t * Height - 0.5f;

			if (dx < 0.0f) dx += Width;
			if (dy < 0.0f) dy += Height;

			int x0 = (int)dx, y0 = (int)dy, x1 = (x0 + 1) % Width, y1 = (y0 + 1) % Height;

			int Width3 = Width * 3;

			BYTE *y0w = y0 * Width3 + Data;
			BYTE *y1w = y1 * Width3 + Data;

			int x03 = x0 * 3, x13 = x1 * 3;

			BYTE *a = y0w + x03;
			BYTE *b = y0w + x13;
			BYTE *c = y1w + x13;
			BYTE *d = y1w + x03;

			float u1 = dx - x0, v1 = dy - y0, u0 = 1.0f - u1, v0 = 1.0f - v1;

			u0 *= OD255;
			u1 *= OD255;

			float u0v0 = u0 * v0, u1v0 = u1 * v0, u1v1 = u1 * v1, u0v1 = u0 * v1;

			double red = u0v0 * a[0] + u1v0 * b[0] + u1v1 * c[0] + u0v1 * d[0];
			double green = u0v0 * a[1] + u1v0 * b[1] + u1v1 * c[1] + u0v1 * d[1];
			double blue = u0v0 * a[2] + u1v0 * b[2] + u1v1 * c[2] + u0v1 * d[2];

			color = Color(u0v0 * a[0] + u1v0 * b[0] + u1v1 * c[0] + u0v1 * d[0], u0v0 * a[1] + u1v0 * b[1] + u1v1 * c[1] + u0v1 * d[1], u0v0 * a[2] + u1v0 * b[2] + u1v1 * c[2] + u0v1 * d[2]);
		}

		return color;
	}

	void CTexture::Destroy()
	{
		if (Data != NULL)
		{
			delete[] Data;
			Data = NULL;
			Width = Height = 0;
		}
	}
	*/
}