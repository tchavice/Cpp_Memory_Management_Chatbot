#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    //delete _chatBot;  //Task 0: removing duplicate chatbot deletion

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

// Task 4 change arg to unique ptr
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge)); //Task 4
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)  //Task 5 - changed arg from ptr to variable
{
    _chatBot = ChatBot(std::move(chatbot)); //Task 5 - used move to pass chatbot
    _chatBot.SetCurrentNode(this);  //Task 5 - removed dereference
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot)); //Task 5 - use move to pass chatBot
    //_chatBot = nullptr; // invalidate pointer at source Task 5 - removed
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    //return _childEdges[index];
    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}