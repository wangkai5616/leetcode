#include<iostream>
#include<string>
using namespace std;
class TrieNode {
public:
	TrieNode *child[26];
	bool isWord;
	TrieNode() :isWord(false)
	{
		for (auto &node : child)
			node = nullptr;
	}
};
class Trie {
public:
	Trie()
	{
		root = new TrieNode();
	}
	//����һ���ַ���s
	void insert(string word)
	{
		TrieNode *p = root;
		for (auto c : word)
		{
			int i = c - 'a';
			if (!p->child[i])
				p->child[i] = new TrieNode();
			p = p->child[i];
		}
		//��ʶһ��������string
		p->isWord = true;
	}
	//�ж��Ƿ���������ַ���key
	bool search(string word)
	{
		TrieNode *p = root;
		for (auto c : word)
		{
			int i = c - 'a';
			if (!p->child[i])
				return false;
			p = p->child[i];
		}
		return p->isWord;
	}
	//�ж��Ƿ����ǰ׺prefix
	bool startsWith(string prefix)
	{
		TrieNode *p = root;
		for (auto c : prefix)
		{
			int i = c - 'a';
			if (!p->child[i])
				return false;
			p = p->child[i];
		}
		return true;
	}
private:
	TrieNode *root;
};