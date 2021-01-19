#include <iostream>
#include <map>
// #include <set>
#include <vector>
#include <algorithm>
#include <cstring>

#include "util.c"
#include "constvar.h"

using namespace std;

struct elem {
    int id;
    int num;

    // 根据id判断是否相等
    bool operator == (const int &id){
        return (this->id == id);
    }
};


bool compareElem (const elem* a, const elem* b) {
    return (a->num > b->num);
}

map<string, vector<elem*> > m;

Status creatIndexstr(string str, int n, int id) {
    char *s;

    s = (char*)malloc(3 * sizeof(char));

    // vector<elem*> v;

    for (int i = 0; i < n; i++) {
        vector<elem*> v;

        if (str[i] > 127 || str[i] < 0) {
            if (i + 2 >= n) {
                return STDINERROR;
            }

            sprintf(s, "%c%c%c", str[i], str[i+1], str[i+2]);

            i += 2;
        } else {
            s[0] = str[i];
            s[1] = '\0';
        }

        if (m.find(s) != m.end()) {
            v = m[s];
            // exist
            /* vector<elem*>::iterator it = find(v.begin(), v.end(), id);
            if (it != v.end()) {
                (*it)->num ++;
            } else {
                elem *temp;
                temp = new elem;
                temp->id = id;
                temp->num = 1;
                m[s].push_back(temp);
            } */
            bool flag = false;
            for (vector<elem*>::iterator t = v.begin(); t != v.end(); t ++) {
                if ((*t)->id == id) {
                    (*t)->num ++;
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                elem *temp;
                temp = new elem;
                temp->id = id;
                temp->num = 1;
                m[s].push_back(temp);
            }
        } else {
            elem *e;
            e = new elem;
            e->id = id;
            e->num = 1;
            v.push_back(e);
            m[s] = v;
        }
    }

    free(s);

    return OK;
}

// 打印索引
Status printIndex() {
    vector<elem*> v;
    cout << "打印索引：" << endl;
    for(map<string, vector<elem*> >::iterator it = m.begin(); it != m.end(); it ++) {
        cout << "key: " << it->first << "\tvalue: \n";
        v = it->second;
        for (vector<elem *>::iterator i = v.begin(); i != v.end(); i ++) {
            cout << "id" << (*i)->id << "\tnum: " << (*i)->num << "\t";
        }
        cout << endl;
    }

    return OK;
}

// 建立倒排索引 不分词 每个字都索引
// 遍历所有 name 建立map<<string> > vector<elem>
// elem.id id elem.num 出现次数
Status initIndex(productLinkPtr head) {
    productLinkPtr p = head->next;
    Status status;

    while(p != NULL) {
        status = creatIndexstr(p->value->name, strlen(p->value->name), p->value->id);
        if (status != OK) {
            return OK;
        }

        p = p->next;
    }

    cout<< "共建立" << m.size() << "个索引！" << endl;

    // printIndex();

    return OK;
}

// 根据 str 查找
// str 按段划分 如果大于 127 按 3 个字节一个算
// map 中 取出 含有这个字的 所有id 累加
Status search(char *str, int n, int *r) {
    char *s;
    vector<elem*> res;
    vector<elem*> v;

    s = (char*)malloc(3 * sizeof(char));
    for (int i = 0; i < n; i++) {
        if (str[i] > 127 || str[i] < 0) {
            if (i + 2 >= n) {
                return STDINERROR;
            }
            sprintf(s, "%c%c%c", str[i], str[i+1], str[i+2]);

            i += 2;
        } else {
            s[0] = str[i];
            s[1] = '\0';
        }

        if (m.find(s) != m.end()) {
            v = m[s];
            // exist
            for (vector<elem*>::iterator it = v.begin(); it != v.end(); it++) {
                /* vector<elem*>::iterator t = find(res.begin(), res.end(), (*it)->id);
                if (t != v.end()) {
                    // 不知道是否赋值成功
                    (*t)->num += (*it)->num;
                } else {
                    elem *temp;
                    temp = new elem;
                    temp->id = (*it)->id;
                    temp->num = (*it)->num;
                    res.push_back(temp);
                } */
                bool flag = false;
                for (vector<elem*>::iterator t = res.begin(); t != res.end(); t ++) {
                    if ((*t)->id == (*it)->id) {
                        (*t)->num += (*it)->num;
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    elem *temp;
                    temp = new elem;
                    temp->id = (*it)->id;
                    temp->num = (*it)->num;
                    res.push_back(temp);
                }
            }
        } else {
           continue;
        }
    }
    
    sort(res.begin(), res.end(), compareElem);
    int i = 0;
    for(vector<elem*>::iterator it = res.begin(); it != res.end(); it ++) {
        cout << "Search success!" << endl;
        cout << "ID: " << (*it)->id << "Weight: " << (*it)->num << endl;

        r[i] = (*it)->id;
        i ++;
    }


    for (vector<elem *>::iterator it = res.begin(); it != res.end(); it ++) 
        if (*it != NULL) {
            delete *it; 
            *it = NULL;
        }
    res.clear();

    free(s);

    return OK;
}

// 释放空间
Status freeIndex() {
    vector<elem*> v;
    elem *e;
    for(map<string, vector<elem*> >::iterator it = m.begin(); it != m.end(); it ++) {
        // cout << "Delete index\t" << (*it)->id << "success!" << endl;

        v = it->second;
        /*for (vector<elem *>::iterator i = v.begin(); i != v.end(); i ++) {
            e = (*i);
            free(e);
            // v.clear();
        }*/
        //e = v[0];
        //cout<< "0: " << e->id << endl;
        vector<elem*>().swap(v);
        //e = v[0];
        //cout<< "0: " << e->id << endl;
        // free(it->first);
    }
    m.clear();

    return OK;
}

// 更新索引
Status renewIndex(productLinkPtr head) {
    freeIndex();

    Status status = initIndex(head);

    return status;
}
