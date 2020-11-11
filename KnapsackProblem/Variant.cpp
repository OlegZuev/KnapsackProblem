#include "Variant.h"
#include <utility>

Variant::Variant(std::vector<Item> items) {
	this->items = std::move(items);
	double weight = 0;
	double value = 0;
	for (const Item& item : this->items) {
		weight += item.weight;
		value += item.value;
	}

	this->sum_weight = weight;
	this->sum_value = value;
}

Variant::Variant(Variant& other) {
	this->items = other.items;
	this->sum_weight = other.sum_weight;
	this->sum_value = other.sum_value;
}

Variant::Variant(const Variant& other) {
	this->items = other.items;
	this->sum_weight = other.sum_weight;
	this->sum_value = other.sum_value;
}

Variant& Variant::operator=(Variant other) {
	swap(*this, other);

	return *this;
}

Variant::Variant(Variant&& other) noexcept {
	swap(*this, other);
}

Variant& Variant::operator=(Variant&& other) noexcept {
	swap(*this, other);

	return *this;
}

void swap(Variant& lhs, Variant& rhs) noexcept {
	using std::swap;

	swap(lhs.items, rhs.items);
	swap(lhs.sum_weight, rhs.sum_weight);
	swap(lhs.sum_value, rhs.sum_value);
}
