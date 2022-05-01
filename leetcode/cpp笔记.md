### CPP笔记

1. 

```c++
//遍历vector容器
for (vector<int>::iterator i = s.begin();i != s.end();i++) {
  cout << *i << endl;
}
//vector排序，默认升序
#include<algorithm>
sort(v.begin(),v.end());
//vector反转
#include<algorithm>
reverse(v.begin(),v.end());
//删除最后一个元素
vector.pop_back();
```

2. 正无穷为```INT_MAX```，负无穷为```INT_MIN```
3. string类型用法

```c++
//获得字符串长度
len = s.size();
//截取某一段字符串,从下标a开始，长度为l的子字符串
new_s = s.substr(a,l);
```

4. vector和set相互转换

```c++
//vector转为set
vector <int> v;
v = {1,2,2,3,4}
set<int> s(v.begin(),v.end());
//set转为vector
v.assign(s.begin(),s.end());
```

5. set用法

```c++
//获取set中元素个数
s.size();
//加入数
s.insert(5);
//删除某数
s.erase(5);
//返回某元素在set中的个数（查找该元素是否在set中）
s.count(5);
```

6. 链表

```c++
//初始化节点
ListNode* l = new ListNode(5);
head -> next = l;
//遍历判断是否到链表尾部
while (l->next != nullptr) {...}
```

