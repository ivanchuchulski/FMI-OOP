#pragma once

#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H

class DynamicStack 
{
public:
	DynamicStack();
	DynamicStack(const DynamicStack& other);
	~DynamicStack();

	DynamicStack& operator=(const DynamicStack& other);

	void Clear();
	bool IsEmpty() const;
	int PeekTop() const;

	int PopOut();
	void PushIn(int elem);

private:
	bool IsFull() const;
	void GrowStack();
	void CopyOtherStack(const DynamicStack& other);

private:
	static const int MAX_SIZE = 50;

private:
	int m_stackTop;
	int m_size;
	int* m_data;
};

#endif // !DYNAMICSTACK_H


