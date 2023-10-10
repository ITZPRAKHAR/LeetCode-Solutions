//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
         unordered_map<Node*,Node*>mp;
         mp[root]=NULL;
         queue<Node*>q;
         q.push(root);
         Node*new_root=NULL;
           while(q.size())
           {
               int x=q.size();
               for(int i=0;i<x;i++)
               {
                  Node*z=q.front();
                  if(target==z->data)
                  {
                      new_root=z;
                  }
                  q.pop();
                    if(z->left)
                    {
                        mp[z->left]=z;
                        q.push(z->left);
                        
                    }
                    if(z->right)
                    {
                        mp[z->right]=z;
                        q.push(z->right);
                    }
                    
               }
           }
           unordered_map<Node*,bool>mp1;
           int l=0;
           queue<Node*>q1;
           q1.push(new_root);
           mp1[new_root]=true;
           while(q1.size())
           {
               int x=q1.size();
                 l++;
               for(int i=0;i<x;i++)
               {
                 Node*z=q1.front();
                   q1.pop();
                  if(z->left&&mp1[z->left]==false)
                  {
                     mp1[z->left]=true;
                     q1.push(z->left);
                  }
                 if(z->right&&mp1[z->right]==false)
                  {
                     mp1[z->right]=true;
                     q1.push(z->right);
                  }
                 if(mp[z]&&mp1[mp[z]]==false)
                  {
                      mp1[mp[z]]=true;
                      q1.push(mp[z]);
                  }
                 
               }
               if(l==k)
               {
                   break;
               }
           }
           vector<int>ans;
           while(q1.size())
           {
             ans.push_back(q1.front()->data);
             q1.pop();
             
           }
           sort(ans.begin(),ans.end());
           return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends