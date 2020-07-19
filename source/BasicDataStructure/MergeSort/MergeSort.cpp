#include"MergeSort.h"

void MergeSort(Vector<Edge>& edges, int start, int end) {
	if (start >= end)return;
	int middle = (start + end) / 2;
	MergeSort(edges, start, middle);
	MergeSort(edges, middle + 1, end);
	Edge* left = new Edge[middle - start + 1];
	for (int i = start; i <= middle; i++)left[i-start] = edges[i];
	Edge* right = new Edge[end - middle];
	for (int i = middle+1; i <= end; i++)right[i-(middle+1)] = edges[i];
	int l = 0,r = 0;
	for (int i = start; i <=end; i++) {
		if (l<=middle-start && ( r>=end-middle || left[l].get_distance() < right[r].get_distance())) {
			edges[i] = left[l];
			l++;
		}
		else {
			edges[i] = right[r];
			r++;
		}
	}
	delete []left;
	delete []right;
}