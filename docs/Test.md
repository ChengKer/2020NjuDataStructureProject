 时间性能如下图所示：

![image-20200720143914232](./pics/image-20200720143914232.png)

对区域染色速度快的原因是因为在第一次染色后图中所有节点的颜色已经被设定好了，后面再运行 `bfs` 时将不会有节点被放入队列中

测试代码如下：具体代码见 `source/Controller/Controller.cpp` 

<img src="./pics/image-20200720143955032.png" alt="image-20200720143955032" style="zoom:80%;" /> 