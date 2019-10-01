fun main(args : Array<String>) {
    var list = ArrayList<Int>()
    list.add(1)
    var stack = Stack<Int>()
    for(i in 0..10)
        stack.push(i)
    while(stack.size > 0)
    {
        println(stack.pop().toString())
    }
}
class Node<T>(data : T,next : Node<T>?)
{
    var data : T = data
    var next : Node<T>? = next
}

class Stack<T>
{
    var head : Node<T>? = null
    var size = 0
    fun push(data : T){
        size++
        head = Node<T>(data,head)
    }
    fun pop(): T? {
        val data : T? = head?.data 
        if(head != null)
            size--
        head = head?.next
        return data
    }

}