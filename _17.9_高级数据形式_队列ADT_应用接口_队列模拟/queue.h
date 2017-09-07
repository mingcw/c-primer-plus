//queue.h -- 队列接口头文件

#ifndef _QUEUE_H_

#define _QUEUE_H_

#include <stdbool.h>

/*在这里键入Item的类型定义*/
//例如
typedef struct item
{
	long arrive;		//一位顾客加入队列的时间
	int processtime;	//该顾客需要的咨询时间
} Item;

#define MAXQUEUE 10		//队列的最大长度

typedef	struct node
{
	Item item;
	struct node * next;
} Node;

typedef struct queue
{
	Node * front;		//指向队列首的指针
	Node * rear;		//指向队列尾的指针
	int items;			//队列中项目的个数
} Queue;

/*操作：初始化队列
操作前：pq指向一个队列
操作后：该队列被初始化为空队列*/
void InitializeQueue(Queue * pq);


/*操作：检查队列是否为空
操作前：pq指向一个已初始化的队列
操作后：如果队列为空，则返回true；
否则返回false*/
bool QueueIsEmpty(const Queue * pq);


/*操作：检查队列是否已满
操作前：pq指向一个已初始化的队列
操作后：如果队列已满，则返回true；
否则返回false*/
bool QueueIsFull(const Queue * pq);


/*操作：确定队列中项目的个数
操作前：pq指向一个已初始化的队列
操作后：返回一个队列中项目的个数*/
int QueueItemCount(const Queue * pq);


/*操作：向队列尾端添加项目
操作前：pq指向一个已初始化的队列
item是要添加到队列尾的项目
操作后：如果队列未满，则将该项目
添加到队列尾，函数返回true；否则
返回false*/
bool EnQueue(Item item, Queue * pq);


/*操作：从队列首端删除项目
操作前：pq指向一个已初始化的队列
操作后：如果队列非空，队列首端的
项目被复制到*pitem,并从队列中删
除，函数返回true；如果这个操作使
队列为空，把队列重置为空队列
如果队列开始时为空，不改变队列，
函数返回false*/
bool DeQueue(Item * pitem, Queue * pq);


/*操作：清空队列
操作前：pq指向一个已经初始化的队列
操作后：队列被清空*/
void EmptyTheQueue(Queue * pq);


#endif // !_QUEUE_H_