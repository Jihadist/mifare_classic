#pragma once
#include "block.h"
#include "trailer.h"
class card
{
	friend std::istream operator>>(const std::istream& lhs, const card& rhs);
public:
	//card() = default;
	explicit card(const byte mem_cnt=1)
	{
		switch (mem_cnt)
		{
		case 1: 
			{
			rawdata = std::make_shared<std::vector<byte>>(16, 0);
			break;
			}
		case 2:
			{
			rawdata = std::make_shared<std::vector<byte>>(32, 0);
			break;
			}
		case 4:
			{
			rawdata = std::make_shared<std::vector<byte>>(64, 0);
			break;
			}
		default:
			{
			throw std::runtime_error("Uncorrected mifare classic type");
			}
		}
	}
	auto begin() const { return rawdata->begin(); }
	auto end() const { return rawdata->end(); }
private:
	std::shared_ptr<std::vector<byte>> rawdata;
};