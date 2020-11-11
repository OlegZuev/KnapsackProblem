#pragma once
#include <vector>
#include "Item.h"

// variant of backpack
class Variant {
public:
	std::vector<Item> items;
	double sum_value{};
	double sum_weight{};

	explicit Variant(std::vector<Item> items);
	Variant() = default;
	virtual ~Variant() = default;
	Variant(Variant& other);
	Variant& operator=(Variant other);
	Variant(Variant&& other) noexcept;
	Variant& operator=(Variant&& other) noexcept;

	friend void swap(Variant& lhs, Variant& rhs) noexcept;
};
