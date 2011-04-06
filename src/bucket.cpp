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
void Bucket::fill() { water = capacity; }

unsigned int Bucket::level() { return water; }
unsigned int Bucket::max() { return capacity; }

Bucket& Bucket::operator++() { ++water; return *this; }
Bucket& Bucket::operator--() { --water; return *this; }

Bucket& Bucket::operator<<(Bucket &_bucket)
{
	while (!isFull() && !_bucket.isEmpty())
	{
		++(*this);
		--_bucket;
	}
	return *this;
}

Bucket& Bucket::operator>>(Bucket &_bucket)
{
	while (!isEmpty() && !_bucket.isFull())
	{
		--(*this);
		++_bucket;
	}
	return *this;
}

bool Bucket::isFull() { return water == capacity; }
bool Bucket::isEmpty() { return water == 0; }
