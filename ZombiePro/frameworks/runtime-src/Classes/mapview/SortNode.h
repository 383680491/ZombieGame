#ifndef _SORTNODE_H_
#define _SORTNODE_H_
#include "cocos2d.h"

bool SortNodeComparisonLess(cocos2d::Node* n1, cocos2d::Node* n2);

class SortNode : public cocos2d::Node
{
public: 
	static void setMaxSortStep(int num);
	static void insertQueuq();
	SortNode();
	virtual ~SortNode(void);
	static SortNode * create();
	virtual void sortAllChildren();
	void setReorder();
	void setNeedSort(bool isneed) {m_needsort = isneed;};
	virtual void visit(cocos2d::Renderer *renderer, const cocos2d::Mat4& parentTransform, uint32_t parentFlags);
private:
	bool m_needsort;
	unsigned int m_nSortStep;
	//std::vector<Node*> m_redraw_node;
};
#endif