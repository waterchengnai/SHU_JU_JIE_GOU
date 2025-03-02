//基本概念:

//路径:从一个节点到另一个节点要走几条连线
//树的路径:从树根到每一个节点的路径和

//结点的权:实际应用中,赋予某些节点(一般是叶节点,这些节点赋予了实际含义,比如及格与否)的数值,比如占比,使用频率
//结点的带权路径长度:从根到结点的路径*权
//树的带权路径长度(WPL):所有叶节点的带权路径长度之和,注意!只算叶节点
//WPL越小,效率越高

//哈夫曼树:WPL最小的树,且权低的结点放在左节点

//对于一组有权的结点,怎么构成哈夫曼树呢

//1.将结点按权重从小到大排序
//2.建立一个新结点N1,把权最小的两个结点给N1当子结点,N1的权为二者和
//3.将N1代替那两个结点参与排序,重复上述操作
//PS:写哈夫曼树时,还要将权低的结点放在左节点

//哈夫曼编码:
//1.将26个英文字母按使用频率作为权,将其构成哈夫曼树
//2.将所有左连线写上0,右连线写上1
//3.将节点对应字母用根到它的路径上的01串来表示,即哈夫曼编码

//前缀编码:跟夫妻肺片没有夫妻一样
//对于任意一个编码,他的编码的前面的01串不和其他编码相同
//如110,1100就不是前缀编码
