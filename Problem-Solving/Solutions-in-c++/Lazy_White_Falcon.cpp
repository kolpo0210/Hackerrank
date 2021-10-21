#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

struct Node
{
    int path;
    int size;
    int depth;
    int parent;
};

struct Path
{
    int root;
    int depth;
    int size;
    vector<int> sums;

    int sum(int ti, int tl, int tr, int l, int r)
    {
        if (l <= r)
        {
            if (l == tl && r == tr)
            {
                return sums[ti];
            }
            else
            {
                int tm = (tl + tr) / 2;
                return sum(2 * ti, tl, tm, l, min(r, tm)) + sum(2 * ti + 1, tm + 1, tr, max(l, tm + 1), r);
            }
        }
        return 0;
    }

    void assign(int value, int ti, int tl, int tr, int i)
    {
        if (i == tl && i == tr)
        {
            sums[ti] = value;
        }
        else
        {
            int tm = (tl + tr) / 2;
            if (i <= tm)
            {
                assign(value, 2 * ti, tl, tm, i);
            }
            else
            {
                assign(value, 2 * ti + 1, tm + 1, tr, i);
            }
            sums[ti] = sums[2 * ti] + sums[2 * ti + 1];
        }
    }

    void assign(int i, int v)
    {
        assign(v, 1, 0, size - 1, i);
    }

    int sum(int l, int r)
    {
        return sum(1, 0, size - 1, l, r);
    }

    Path(int root, int depth, int size) : root(root), depth(depth), size(size)
    {
        int temp = 1;
        while (temp <= size)
        {
            temp <<= 1;
        }
        sums.resize(2 * temp, 0);
    }
};

class Tree
{
    vector<Path> paths;
    vector<Node> nodes;

    bool isHeavy(int node)
    {
        int parent = nodes[node].parent;
        return (parent < 0) ? false : (2 * nodes[node].size >= nodes[parent].size);
    }

public:
    Tree(vector<vector<int>>& edges)
    {
        vector<vector<int>> tree(edges.size() + 1);
        for (int i = 0; i < edges.size(); i++)
        {
            tree[edges[i][0]].push_back(edges[i][1]);
            tree[edges[i][1]].push_back(edges[i][0]);
        }

        nodes.resize(edges.size() + 1);
        init(0, -1, 0, tree);
        createPaths(0, -1, tree);
    }

    void init(int curr, int parent, int depth, vector<vector<int>>& tree)
    {
        nodes[curr].size = 1;
        nodes[curr].depth = depth;
        nodes[curr].parent = parent;
        for (int i = 0; i < tree[curr].size(); i++)
        {
            int next = tree[curr][i];
            if (next != parent)
            {
                init(next, curr, depth + 1, tree);
                nodes[curr].size += nodes[next].size;
            }
        }
    }

    void createPaths(int curr, int parent, vector<vector<int>>& tree)
    {
        bool hasHeavy = false;
        for (int i = 0; i < tree[curr].size(); i++)
        {
            int next = tree[curr][i];
            if (next != parent)
            {
                createPaths(next, curr, tree);
                if (isHeavy(next))
                {
                    hasHeavy = true;
                }
            }
        }
        if (!hasHeavy)
        {
            createPath(curr);
        }
    }

    void createPath(int node)
    {
        int length = 1;
        while (true)
        {
            nodes[node].path = paths.size();
            if (!isHeavy(node))
            {
                break;
            }
            node = nodes[node].parent;
            length += 1;
        }
        paths.push_back(Path(node, nodes[node].depth, length));
    }

    void assign(int node, int value)
    {
        int path = nodes[node].path;
        paths[path].assign(nodes[node].depth - paths[path].depth, value);
    }

    int sum(int u, int v)
    {
        if (nodes[u].path == nodes[v].path)
        {
            int path = nodes[u].path;
            int l = std::min(nodes[u].depth, nodes[v].depth);
            int r = std::max(nodes[u].depth, nodes[v].depth);
            return paths[path].sum(l - paths[path].depth, r - paths[path].depth);
        }
        int rootU = paths[nodes[u].path].root;
        int rootV = paths[nodes[v].path].root;
        if (nodes[rootU].depth < nodes[rootV].depth)
        {
            int path = nodes[v].path;
            return paths[path].sum(0, nodes[v].depth - paths[path].depth) + sum(u, nodes[rootV].parent);
        }
        else
        {
            int path = nodes[u].path;
            return paths[path].sum(0, nodes[u].depth - paths[path].depth) + sum(nodes[rootU].parent, v);
        }
    }
};

vector<int> solve(vector<vector<int>>& edges, vector<vector<int>>& queries)
{
    Tree tree(edges);
    vector<int> res;
    for (int i = 0; i < queries.size(); i++)
    {
        if (queries[i][0] == 1)
        {
            tree.assign(queries[i][1], queries[i][2]);
        }
        else
        {
            res.push_back(tree.sum(queries[i][1], queries[i][2]));
        }
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nq_temp;
    getline(cin, nq_temp);

    vector<string> nq = split_string(nq_temp);

    int n = stoi(nq[0]);

    int q = stoi(nq[1]);

    vector<vector<int>> tree(n-1);
    for (int tree_row_itr = 0; tree_row_itr < n-1; tree_row_itr++) {
        tree[tree_row_itr].resize(2);

        for (int tree_column_itr = 0; tree_column_itr < 2; tree_column_itr++) {
            cin >> tree[tree_row_itr][tree_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<vector<int>> queries(q);
    for (int queries_row_itr = 0; queries_row_itr < q; queries_row_itr++) {
        queries[queries_row_itr].resize(3);

        for (int queries_column_itr = 0; queries_column_itr < 3; queries_column_itr++) {
            cin >> queries[queries_row_itr][queries_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = solve(tree, queries);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
