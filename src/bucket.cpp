#include "bucket.hpp"

Bucket::Bucket(unsigned int _capacity, unsigned int _water) : capacity(_capacity)
{
	water = _water;
}

Bucket::Bucket(Bucket &_bucket) : capacity(_bucket.capacity)
{
	water = _bucket.water;
}

void Bucket::empty() { water = 0; }
void Bucket::full() { water = capacity; }

unsigned int Bucket::level() { return water; }
unsigned int Bucket::max() { return capacity; }

Bucket& Bucket::operator++() { ++water; return *this; }
Bucket& Bucket::operator--() { --water; return *this; }

Bucket& Bucket::operator<<(Bucket &_bucket)
{
	while (water < capacity && _bucket.water > 0)
	{
		++(*this);
		--_bucket;
	}
	return *this;
}

Bucket& Bucket::operator>>(Bucket &_bucket)
{
	while (water > 0 && _bucket.water < _bucket.capacity)
	{
		--(*this);
		++_bucket;
	}
	return *this;
}
