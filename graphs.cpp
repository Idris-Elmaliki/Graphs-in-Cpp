#include <iostream>
#include <unordered_map>
#include <unordered_set>

class Graph { 
    std::unordered_map<std::string, std::unordered_set<std::string>> adjList; 

public: 
    bool addVertex(std::string vertex) {
        if(adjList.count(vertex) == 0) {
            adjList[vertex]; 
            return true; 
        }

        return false; 
    }

    bool addEdge(std::string vertex1, std::string vertex2) {
        if(adjList.find(vertex1) != adjList.end() && adjList.find(vertex2) != adjList.end()) {
            adjList.at(vertex1).insert(vertex2); 
            adjList.at(vertex2).insert(vertex1);
            return true; 
        }

        return false; 
    }

    bool removeVertex(std::string vertex) {
        if(adjList.find(vertex) != adjList.end()) {
            for(auto edge : adjList.at(vertex)) {
                adjList.at(edge).erase(vertex); 
            }
            adjList.erase(vertex); 
            return true; 
        }

        return false; 
    }

    bool removeEdge(std::string vertex1, std::string vertex2) {
        if(adjList.find(vertex1) != adjList.end() && adjList.find(vertex2) != adjList.end()) {
            adjList.at(vertex1).erase(vertex2); 
            adjList.at(vertex2).erase(vertex1); 
            return true; 
        }

        return false; 
    }

    void printGraph() {
        for(auto [vertex, edges] : adjList) {
            std::cout << vertex << ": ["; 
            for(auto edge: edges) {
                std::cout << edge; 
            }
            std::cout << "]\n"; 
        }
    }

}; 