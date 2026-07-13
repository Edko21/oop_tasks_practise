#include "Policy.h"

static const int MAX_SIZE = 200;

class BulFmi {
public:
	BulFmi(double budget);
	BulFmi(const BulFmi& other);
	BulFmi& operator=(const BulFmi& other);
	~BulFmi();

	bool addPolicy(Policy* p);
	bool removePolicy(int ind);

	Policy* getPolicy(int ind);
	const Policy* getPolicy(int ind) const;

	double getInsuranceAmount(int ind) const;
	void printAll() const;
	int getSize() const;
	double getBudget() const;

	bool canAdd(const Policy* p);

private:
	Policy* p[MAX_SIZE];
	int size;
	double budget;
	void clear();
	void copyFrom(const BulFmi& other);
};