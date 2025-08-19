#include <stdio.h>
#define MAX_EDGES 30
struct GraphEdge {
    int from, to, weight;
};
int leader[MAX_EDGES];
int findLeader(int node) {
    while (leader[node] != node)
        node = leader[node];
    return node;
}
void mergeSets(int node1, int node2) {
    int root1 = findLeader(node1);
    int root2 = findLeader(node2);
    leader[root1] = root2;
}
int main() {
    int numVertices, numEdges;
    struct GraphEdge edgeList[MAX_EDGES], swapEdge;
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter number of edges: ");
    scanf("%d", &numEdges);
    printf("Enter edges (U V Weight):\n");
    for (i = 0; i < numEdges; i++) {
        char start, end;
        int w;
        scanf(" %c %c %d", &start, &end, &w);
        int sIndex, eIndex;
        if (start == 'L') sIndex = 1;
        if (start == 'H') sIndex = 2;
        if (start == 'C') sIndex = 3;
        if (start == 'B') sIndex = 4;
        if (start == 'A') sIndex = 5;
        if (end == 'L') eIndex = 1;
        if (end == 'H') eIndex = 2;
        if (end == 'C') eIndex = 3;
        if (end == 'B') eIndex = 4;
        if (end == 'A') eIndex = 5;
        edgeList[i].from = sIndex;
        edgeList[i].to = eIndex;
        edgeList[i].weight = w;
    }
    for (i = 0; i < numEdges - 1; i++) {
        for (j = 0; j < numEdges - i - 1; j++) {
            if (edgeList[j].weight > edgeList[j + 1].weight) {
                swapEdge = edgeList[j];
                edgeList[j] = edgeList[j + 1];
                edgeList[j + 1] = swapEdge;
            }
        }
    }
    for (i = 1; i <= numVertices; i++)
        leader[i] = i;
    int mstCost = 0;
    printf("\nEdges chosen for MST:\n");
    for (i = 0; i < numEdges; i++) {
        int u = edgeList[i].from;
        int v = edgeList[i].to;
        if (findLeader(u) != findLeader(v)) {
            mergeSets(u, v);
            mstCost += edgeList[i].weight;
            char labelU, labelV;
            if (u == 1) labelU = 'L';
            if (u == 2) labelU = 'H';
            if (u == 3) labelU = 'C';
            if (u == 4) labelU = 'B';
            if (u == 5) labelU = 'A';
            if (v == 1) labelV = 'L';
            if (v == 2) labelV = 'H';
            if (v == 3) labelV = 'C';
            if (v == 4) labelV = 'B';
            if (v == 5) labelV = 'A';
            printf("%c - %c : %d\n", labelU, labelV, edgeList[i].weight);
        }
    }
    printf("\nTotal MST Cost = %d\n", mstCost);
    return 0;
}

