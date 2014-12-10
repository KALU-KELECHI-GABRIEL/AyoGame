#ifndef CUP_H
#define CUP_H

// class represents each individual cup. 
class Cup
{
private:
	int m_numberOfSeeds;

public:
    // Default Constructor
    Cup() {	m_numberOfSeeds = 4; }
 
	int GetSeeds() { return m_numberOfSeeds; }      

	void emptyCup() { m_numberOfSeeds = 0; }
	void incrementSeeds() { m_numberOfSeeds++; }
};

#endif