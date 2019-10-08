#include <iostream>
#include <stack>
using namespace std;

class stackQueue
{
	stack<int> m_st1;
public:
	stackQueue()
	{

	}
	void push(int x)
	{
		m_st1.push(x);
	}
	void pop()
	{
		stack<int> m_st2;
		while (m_st1.size() > 1)
		{
			m_st2.push(m_st1.top());
			m_st1.pop();
		}
		m_st1.pop();
		while (!m_st2.empty())
		{
			m_st1.push(m_st2.top());
			m_st2.pop();
		}
	}
	int front()
	{
		stack<int> m_st2;
		while (m_st1.size() > 1)
		{
			m_st2.push(m_st1.top());
			m_st1.pop();
		}
		int tmp = m_st1.top();
		while (!m_st2.empty())
		{
			m_st1.push(m_st2.top());
			m_st2.pop();
		}
		return tmp;
	}
	bool empty()
	{
		return !m_st1.size();
	}

};


int main()
{
	stackQueue sq;

	sq.push(1);
	sq.push(2);
	sq.push(3);
	sq.push(4);

	cout << sq.front() << endl;
	sq.pop();
	cout << sq.front() << endl;
	sq.pop();
	cout << sq.front() << endl;
	sq.pop();
	cout << sq.front() << endl;
	cout << sq.empty() << endl;


	return 0;
}