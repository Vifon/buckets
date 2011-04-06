#ifndef BUCKET
#define BUCKET 1

class Bucket
{
	private:
		unsigned int water;
		const unsigned int capacity;

		Bucket& operator++();
		Bucket& operator--();
	public:
		Bucket(unsigned int _capacity, unsigned int _water = 0);
		Bucket(Bucket &_bucket);

		void empty();
		void full();

		unsigned int level();
		unsigned int max();

		Bucket& operator<<(Bucket &_bucket);
		Bucket& operator>>(Bucket &_bucket);
};

#endif
