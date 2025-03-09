//将非二叉树转换成二叉树需要三个步骤

//1.将所有兄弟节点之间连线(兄弟结点就是同一个妈的子节点)
//2.将所有节点的子节点的连线去掉,除了第一个结点
//3.将所有节点重新排版,将保留的子节点作为左孩子,兄弟结点当作右孩子

//①这样操作使所有转化后的二叉树根结点都没有右孩子

//将二叉树转换为非二叉树

//1.若一个结点有左孩子,则将左孩子的右孩子这一脉的全部右孩子(就是往右这条线走到黑)都与该结点连线
//2.所有有右孩子的结点全部与右孩子去线,(我觉得应该除了根节点)
//3.调整一下,重新排版

//将森林转换成一个二叉树

//首先说一下啥是森林
//森林：一堆没关系的树

//转换过程：
//1.首先将所有树二叉树化
//2.然后从第二棵树开始，将树的根节点当作前一棵树的根节点的右孩子

//将二叉树转成森林
//1.从根节点一直往右走，遇到连线就删除，剩下的树再非二叉化

//森林转化成二叉树
//从根节点开始，若有右孩子，则去掉右孩子的连线//3.调整一下,重新排版

//将森林转换成一个二叉树

//首先说一下啥是森林
//森林：一堆没关系的树
//②森林中：
//树+边数=节点数
//因为每棵树中，结点数都比边数多一
//③由一可得，最后的二叉树从根开始，往右的连线有几个，就有几个右孩子


//转换过程：
//1.首先将所有树二叉树化
//2.然后从第二棵树开始，将树的根节点当作前一棵树的根节点的右孩子

//将二叉树转成森林
//1.从根节点一直往右走，遇到连线就删除，剩下的树再非二叉化

//对于树来说他的遍历方法比二叉树要少
//只有前根遍历和后根遍历,因为无法确定谁为中间
//这两种方式的遍历逻辑很接近前序和后续,前序就是先老子再孩子,后序就是先孩子再老子,没有左右之说了

//森林
//森林又有不同,叫前序和中序遍历
//但是要注意:森林虽然叫中序遍历,但是逻辑确实跟后根遍历的逻辑一样

//下面的表是逻辑对应表,同一行逻辑相同

//	树				     森林			   二叉树
//					
//先根遍历			   前序遍历			  前序遍历
//后根遍历			   中序遍历			  中序遍历
