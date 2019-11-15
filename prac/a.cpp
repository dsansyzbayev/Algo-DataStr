#include <iostream>
#include <cassert>
using namespace std;

struct node {
        int val,height;
        node *l;
        node *r;

        node(int val)
        {
                this->height = 0;
                this->val = val;
                this->l = nullptr;
                this->r = nullptr;
        }
};

int geth(node *v) {
        if (v == nullptr) return 0;
        return v->height;
}
int getsum(node *rt,int height)
{
        if (rt == nullptr)
        {
                return 0;
        }
        if (height == 1)
        {
                return rt->val;
        }
        return(getsum(rt->l,height-1)+getsum(rt->r,height-1));
}



void addnode(node *&v,int val)
{
        if(v == nullptr)
        {
                v=new node(val);
                return;
        }
        if(val <= v->val)
        {
                addnode(v->l,val);
        }
        else
        {
                addnode(v->r,val);
        }
        v->height = max(geth(v->l), geth(v->r)) + 1;
}

//test
int main()
{
        node *root = nullptr;
        //assert(root == nullptr);

        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
                int k;
                cin >> k;
                addnode(root,k);                /* code */
        }
        int h = root->height+1;
        cout << h << endl;
        for (int i = 1; i <= h; ++i)
        {
                cout << getsum(root,i) << " ";
        }



        return 0;
}