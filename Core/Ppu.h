#pragma once
#include "stdafx.h"
#include "PpuTypes.h"

class Console;
class InternalRegisters;

class Ppu
{
public:
	constexpr static uint32_t SpriteRamSize = 544;
	constexpr static uint32_t CgRamSize = 512;
	constexpr static uint32_t VideoRamSize = 0x10000;

private:
	shared_ptr<Console> _console;
	shared_ptr<InternalRegisters> _regs;

	uint16_t _cycle = 0;
	uint16_t _scanline = 0;
	uint32_t _frameCount = 0;
	
	uint8_t _bgMode = 0;
	LayerConfig _layerConfig[4];
	
	uint8_t *_vram;
	uint16_t _vramAddress;
	uint8_t _vramIncrementValue;
	uint8_t _vramAddressRemapping;
	bool _vramAddrIncrementOnSecondReg;
	
	uint16_t _cgramAddress;
	uint8_t _cgram[Ppu::CgRamSize];

	uint16_t *_outputBuffers[2];
	uint16_t *_currentBuffer;

	uint8_t _oamMode = 0;
	uint8_t _oamBaseAddress = 0;
	uint8_t _oamAddressOffset = 0;

	uint8_t _oamRam[Ppu::SpriteRamSize];
	uint16_t _oamRamAddress = 0;
	bool _enableOamPriority = false;
	
	uint16_t _internalOamAddress = 0;
	uint8_t _oamWriteBuffer = 0;

	void RenderTilemap(LayerConfig &config, uint8_t bpp);

public:
	Ppu(shared_ptr<Console> console);
	~Ppu();

	uint32_t GetFrameCount();
	PpuState GetState();

	void Exec();

	void SendFrame();

	uint8_t* GetVideoRam();
	uint8_t* GetCgRam();
	uint8_t* GetSpriteRam();

	uint8_t Read(uint16_t addr);
	void Write(uint32_t addr, uint8_t value);
};