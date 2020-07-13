#include <iostream>
#include <string>
#include <vector>

using namespace std;

class node{
private:
public:
	string name;
	node *l_p;
	node *r_p;
	double blood;
	node()
	{
		name = "";
		l_p = NULL;
		r_p = NULL;
		blood = 0.0;
	}
	node(string n, node *l=NULL, node *r=NULL, double b=0.0)
	{
		name = n;
		l_p = l;
		r_p = r;
		blood = b;
	}
	void set_name(string n){    name = n;	}
	void set_l_p(node * l){    l_p = l;	}
	void set_r_p(node * r){    r_p = r;	}
	void set_blood(double b){    blood = b;	}		
};

int N, M;
vector <node> loyal_fam;
vector <string> candidates;

int is_loyal_fam(string name)
{
	for(int i=0; i<(int)loyal_fam.size();i++)
	{
		if (loyal_fam[i].name == name)
		{
			return i;
		}
	}
	return -1;
}

double calculate_blood(string name)
{
	int fam_idx = is_loyal_fam(name);
	if (fam_idx==-1)
	{
		return 0.0;
	}
	else
	{
		node _node = loyal_fam[fam_idx];
		if (_node.l_p == NULL && _node.r_p == NULL)
		{
			return _node.blood;
		}
		else
		{
			return 0.5 * (calculate_blood(_node.l_p->name) + calculate_blood(_node.r_p->name));
		}
	}
}

int main()
{
	cin >> N >> M;
	fflush(stdin);
	
	string s;
	cin >> s;
	fflush(stdin);
	
	node utopia = node(s, NULL, NULL, 1.0);
	utopia.name = s;
	utopia.blood = 1.0;
	loyal_fam.push_back(utopia);
	
	string c, l, r;
	int l_idx, r_idx;
	node tmp, l_node, r_node;
	
	for(int i=0; i<N; i++)
	{
		c = l = r = "";
		l_idx = r_idx = 0;
		
		cin >> c >> l >> r;
		fflush(stdin);
		
		l_idx = is_loyal_fam(l);
		r_idx = is_loyal_fam(r);
		
		if (l_idx > -1)
			l_node = loyal_fam[l_idx];
		else
			l_node = node(l);
		if (r_idx > -1)
			r_node = loyal_fam[r_idx];
		else
			r_node = node(r);
		
		tmp = node(c, &l_node, &r_node);
		loyal_fam.push_back(tmp);		
	}
	
	for(int i=0; i<M;i++)
	{
		cin >> c;
		candidates.push_back(c);
	}
	
	string answer = "";
	double max_blood, cand_blood = 0.0;
	
	for(int i=0; i<(int)candidates.size();i++)
	{
		cand_blood = calculate_blood(candidates[i]);
		if (max_blood < cand_blood)
		{
			answer = candidates[i];
			max_blood = cand_blood;
		}
	}
	
	cout << answer;
	
	return 0;
}
