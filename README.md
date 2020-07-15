# 2020NjuDataStructureProject
本项目为南京大学2020年暑期数据结构的期末项目

项目模块划分如下：

```mermaid
graph TB
a1(main)
a2(controller)
a1-->a2
a3(graph)
a2-->a3
a4(file)
a3-->a4
a5(g_distance)
a3-->a5
a6(g_paint)
a3-->a6
a7(g_selectInfo)
a3-->a7
a8(g_plan)
a3-->a8
a10(node)
a4-->a10
a5-->a10
a6-->a10
a7-->a10
a8-->a10
```

- **main**：程序运行的入口
- **controller**：负责程序的流程控制，根据用户的不同输入采取调用不同的行为
- **graph**：图模块，包括图类的定义和项目各种功能的定义
- **file**：从文件中读取数据生成图结构
- **g_distance**：完成求两结点间最短路径的功能，具体的实现：
  - 快速计算：在程序初始化时调用沃舍尔算法计算，在查询时直接查找给出结果
  - 及时计算：采用贝尔曼-福特算法及时计算，给出完整的路线
- **g_paint**：采用回溯算法完成图染色的功能
- **g_selectionInfo**：使用二叉搜索树进行数据的查询
- **g_plan**：采用克鲁斯卡尔算法进行最小生成树的计算，从而输出结果
- **node**：结点数据类型，存储了一个结点有关的相应信息

