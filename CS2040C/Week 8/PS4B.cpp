// PS4B
#include <bits/stdc++.h>
using namespace std;

typedef string MP_Key_Type;
typedef string MP_Value_Type;

// Vertex structure
struct MP_Vertex {
	MP_Key_Type key;
	MP_Value_Type item;
	MP_Vertex* parent;
	MP_Vertex* left;
	MP_Vertex* right;
	int height;			// height of vertex
	int bf;				// balance factor
	int children;		// number of vertex with it as their ancestor
	int left_children;	// number of vertex in its left subtree
	int right_children;	// number of vertex in its right subtree
};

class MP {
private:
	// Class elements
	int num_elements;
	MP_Vertex* root;
	
	// Update elements
	MP_Vertex* create_leaf(MP_Key_Type key, MP_Value_Type value) {
		MP_Vertex* vtx = new MP_Vertex();
		vtx->key = key;
		vtx->item = value;
		vtx->left = NULL;
		vtx->right = NULL;
		vtx->height = 0;
		vtx->bf = 0;
		vtx->children = 0;
		vtx->left_children = 0;
		vtx->right_children = 0;
		return vtx;
	}
	void update_vertex(MP_Vertex* vtx) {
		if (vtx == NULL)
			return;
		MP_Vertex* L = vtx->left;
		MP_Vertex* R = vtx->right;
		int L_height = (L != NULL) ? (L->height) : (-1);
		int R_height = (R != NULL) ? (R->height) : (-1);
		vtx->height = 1 + max(L_height, R_height);
		vtx->bf = L_height - R_height;
		vtx->left_children = (L != NULL) ? (L->children + 1) : (0);
		vtx->right_children = (R != NULL) ? (R->children + 1) : (0);
		vtx->children = vtx->left_children + vtx->right_children;
	}
	
	// Rotations
	MP_Vertex* rotate_left(MP_Vertex* vtx) {
		MP_Vertex* new_root = vtx->right;	// != NULL
		MP_Vertex* root_parent = vtx->parent;
		MP_Vertex* new_right = (vtx->right)->left;
		new_root->left = vtx;
		vtx->parent = new_root;
		new_root->parent = root_parent;
		if (root_parent != NULL) {
			if (root_parent->left == vtx)
				root_parent->left = new_root;
			else
				root_parent->right = new_root;
		} else
			root = new_root;
		vtx->right = new_right;
		if (new_right != NULL)
			new_right->parent = vtx;
		update_vertex(vtx);
		update_vertex(new_root);
		return new_root;
	}
	MP_Vertex* rotate_right(MP_Vertex* vtx) {
		MP_Vertex* new_root = vtx->left;	// != NULL
		MP_Vertex* root_parent = vtx->parent;
		MP_Vertex* new_left = (vtx->left)->right;
		new_root->right = vtx;
		vtx->parent = new_root;
		new_root->parent = root_parent;
		if (root_parent != NULL) {
			if (root_parent->left == vtx)
				root_parent->left = new_root;
			else
				root_parent->right = new_root;
		} else
			root = new_root;
		vtx->left = new_left;
		if (new_left != NULL)
			new_left->parent = vtx;
		update_vertex(vtx);
		update_vertex(new_root);
		return new_root;
	}
	
	// Balancing BST
	void rebalance(MP_Vertex* vtx) {
		while(vtx != NULL) {
			update_vertex(vtx);
			if (vtx->bf == 2) {
				if ((vtx->left)->bf == -1)
					rotate_left(vtx->left);
				vtx = rotate_right(vtx);
			} else if (vtx->bf == -2) {
				if ((vtx->right)->bf == 1)
					rotate_right(vtx->right);
				vtx = rotate_left(vtx);
			}
			vtx = vtx->parent;
		}
	}
	
	// Find insertion point
	void find_and_insert(MP_Vertex* vtx) {
		bool inserted = 0;
		MP_Vertex* it = root;
		while (inserted == 0) {
			if (it->key < vtx->key) {
				if (it->right != NULL)
					it = it->right;
				else {
					it->right = vtx;
					vtx->parent = it;
					inserted = 1;
				}
			} else {
				if (it->left != NULL)
					it = it->left;
				else {
					it->left = vtx;
					vtx->parent = it;
					inserted = 1;
				}
			}
		}
		rebalance(it);
	}

public:
	// Constructor
	MP() {
		num_elements = 0;
		root = NULL;
	}
	
	// Modifiers
	void insert(MP_Key_Type key, MP_Value_Type value) {
		if (find(key) != NULL)
			return;
		num_elements += 1;
		MP_Vertex* vtx = create_leaf(key,value);
		if (root == NULL) {
			vtx->parent = NULL;
			root = vtx;
		} else
			find_and_insert(vtx);
	}
	void erase(MP_Key_Type key) {
		MP_Vertex* vtx = find(key);
		while (vtx != NULL) {
			erase(vtx);
			vtx = find(key);
		}
	}
	void erase(MP_Vertex* vtx) {
		MP_Vertex* prt = vtx->parent;
		MP_Vertex* L = vtx->left;
		MP_Vertex* R = vtx->right;
		if ((L==NULL) || (R==NULL)) {
			num_elements -= 1;
			if (L == NULL)
				L = R;
			if (L != NULL)
				L->parent = prt;
			if (prt == NULL)
				root = L;
			else {
				if (prt->left == vtx)
					prt->left = L;
				else
					prt->right = L;
				rebalance(prt);
			}
			delete vtx;
		} else {
			MP_Vertex* scc = successor(vtx);
			vtx->key = scc->key;
			vtx->item = scc->item;
			erase(scc);
		}
	}
	
	// Lookup
	MP_Vertex* find(MP_Key_Type key) {
		MP_Vertex* vtx = root;
		while ((vtx != NULL) && (vtx->key != key))
			if (vtx->key < key)
				vtx = vtx->right;
			else
				vtx = vtx->left;
		return vtx;
	}
	MP_Vertex* lower_bound(MP_Key_Type key) {
		MP_Vertex* vtx = NULL;
		MP_Vertex* next_vtx = root;
		while (next_vtx != NULL)
			if (next_vtx->key == key) {
				vtx = next_vtx;
				break;
			} else if (next_vtx->key < key)
				next_vtx = next_vtx->right;
			else {
				vtx = next_vtx;
				next_vtx = next_vtx->left;
			}
		return vtx;
	}
	MP_Vertex* successor(MP_Key_Type key) {
		MP_Vertex* vtx = find(key);
		return successor(vtx);
	}
	MP_Vertex* successor(MP_Vertex* vtx) {
		if (vtx->right != NULL) {
			while (vtx->right != NULL)
				vtx = vtx->right;
			return vtx;
		} else {
			MP_Vertex* prt = vtx->parent;
			while ((prt != NULL) && (prt->key < vtx->key)) {
				vtx = prt;
				prt = prt->parent;
			}
			return prt;
		}
	}
	int rank(MP_Key_Type key) {
		MP_Vertex* vtx = find(key);
		return rank(vtx);
	}
	int rank(MP_Vertex* vtx) {
		if (vtx == NULL)
			return num_elements + 1;
		else {
			int result = 1 + vtx->left_children;
			MP_Vertex* prt = vtx->parent;
			while (prt != NULL) {
				if (prt->key < vtx->key)
					result += (1 + prt->left_children);
				vtx = prt;
				prt = prt->parent;
			}
			return result;
		}
	}
	
	// Traversal
	void inorder_traversal() {
		inorder_traversal(root);
	}
	void inorder_traversal(MP_Vertex* vtx) {
		if (vtx == NULL)
			return;
		else {
			inorder_traversal(vtx->left);
			cout << vtx->key << " " << vtx->item << endl;
			inorder_traversal(vtx->right);
			return;
		}
	}
	void preorder_traversal() {
		preorder_traversal(root);
	}
	void preorder_traversal(MP_Vertex* vtx) {
		if (vtx == NULL)
			return;
		else {
			cout << vtx->key << " " << vtx->item << endl;
			preorder_traversal(vtx->left);
			preorder_traversal(vtx->right);
			return;
		}
	}
	void postorder_traversal() {
		postorder_traversal(root);
	}
	void postorder_traversal(MP_Vertex* vtx) {
		if (vtx == NULL)
			return;
		else {
			postorder_traversal(vtx->left);
			postorder_traversal(vtx->right);
			cout << vtx->key << " " << vtx->item << endl;
			return;
		}
	}
};

class suggestionsList {
private:
	MP maleNamesList;
	MP femaleNamesList;
public:
	void AddSuggestion(string name,int gender) {
		if (gender == 1)
			maleNamesList.insert(name,name);
		else
			femaleNamesList.insert(name,name);
	}
	void RemoveSuggestion(string name) {
		maleNamesList.erase(name);
		femaleNamesList.erase(name);
	}
	int Query(string Start, string End, int gender) {
		int count = 0;
		if ((gender==0) || (gender==1)) {
			MP_Vertex* Mfirst = maleNamesList.lower_bound(Start);
			MP_Vertex* Mlast = maleNamesList.lower_bound(End);
			int MfirstRank = maleNamesList.rank(Mfirst);
			int MlastRank = maleNamesList.rank(Mlast);
			count += (MlastRank - MfirstRank);
		}
		if ((gender==0) || (gender==2)) {
			MP_Vertex* Ffirst = femaleNamesList.lower_bound(Start);
			MP_Vertex* Flast = femaleNamesList.lower_bound(End);
			int FfirstRank = femaleNamesList.rank(Ffirst);
			int FlastRank = femaleNamesList.rank(Flast);
			count += (FlastRank - FfirstRank);
		}
		return count;
	}
	/*
	void PrintOut() {
		cout << endl;
		maleNamesList.preorder_traversal();
		femaleNamesList.preorder_traversal();
		cout << endl;
		maleNamesList.inorder_traversal();
		femaleNamesList.inorder_traversal();
	}
	*/
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// freopen("in.txt", "r", stdin);
	// clock_t start, finish;
	// start = clock();
	
	suggestionsList NamesList;
	int n, gender;
	string s1, s2;
	while(cin >> n, n!=0) {
		if (n==1) {
			cin >> s1 >> gender;
			NamesList.AddSuggestion(s1,gender);
		} else if (n==2) {
			cin >> s1;
			NamesList.RemoveSuggestion(s1);
		} else {
			cin >> s1 >> s2 >> gender;
			cout << NamesList.Query(s1,s2,gender) << endl;
		}
	}
	
	// NamesList.PrintOut();
	// finish = clock();
	// cout << "Running time: " << (double) (finish-start)/CLOCKS_PER_SEC << endl;
	
	return 0;
}