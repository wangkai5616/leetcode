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
	//插入一个字符串s
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
		//标识一个完整的string
		p->isWord = true;
	}
	//判断是否存在完整字符串key
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
	//判断是否存在前缀prefix
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