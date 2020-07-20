## 模块划分

#### 本项目共12个模块，划分如下：

![image-20200720083732553](C:\Users\Orange\AppData\Roaming\Typora\typora-user-images\image-20200720083732553.png)

**mian**：主模块，是程序的入口

**Controller**：控制模块，根据用户的不同输入调用 `Graph` 的不同方法，并进行相应信息的输出

**Graph**：图模块，关于图所有的功能都在这里实现，其中包括 `BuildGraph`，`SelectInfo`，`Distance`，`Plan`和 `PaintGraph`

**File**：文件模块，从文件中读取相关信息的模块，提供了按流读取`get_flow`和按行读取`get_line`两种方式，在`Graph` 中用来从数据文件中读取数据生成图结构

**Node**：结点模块，图中结点(行政区域)的数据结构，其中包括 `_index`，`_name`，`_info` 三个数据成员，分别是行政区域编号，行政区域名，行政区域详细信息

**Edge**：边模块，图中边的数据结构，其中包括 `_city_x`，`_city_y`，`_distance` 三个数据成员，分别是边的两个端点城市和两个城市之间的距离。在 `Plan` 功能实现的过程中，需要提供**边**结构 

**Vector**：向量模块，顺序数组类模板，用来在图中存储边结构。

**UnionFindSet**：并查集模块，用在 `Plan` 功能的实现中

**MergeSort**：归并排序模块，用在 `Plan` 功能的实现中

**Queue**：队列模块，用在`Paint` 功能的实现中，为 `bfs` 提供了存储结点的容器

**HashTable**：哈希表模块，用在`SelectInfo` 功能的实现中和需要**通过行政区名**检索**行政区编号**的所有场景中，其采用链式开散列实现，每个“桶”都是一个`BST`，极大的提高了检索的效率，具体结构如下：

<img src="C:\Users\Orange\AppData\Roaming\Typora\typora-user-images\image-20200720083137931.png" alt="image-20200720083137931" style="zoom: 50%;" />

**BinarySearchTree**：二分查找树，用来作为 `HashTable` 每一个“桶”的数据结构



## 功能实现

### 本项目主要功能的实现方法如下：

