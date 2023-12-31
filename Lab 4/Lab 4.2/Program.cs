﻿using System.Collections;

namespace double_list
{
	class Program
	{
		public class DoubleNode<T>
		{
			public DoubleNode(T data)
			{
				Data = data;
			}

			public T Data { set; get; }
			public DoubleNode<T> Previous { set; get; }
			public DoubleNode<T> Next { set; get; }
		}

		public class DoubleLinkedList<T> : IEnumerable<T>
		{
			DoubleNode<T> head;
			DoubleNode<T> tail;
			int count;

			public void AddLast(T data)
			{
				DoubleNode<T> node = new DoubleNode<T>(data);

				if (head == null)
				{
					head = node;
				}
				else
				{
					tail.Next = node;
					node.Previous = tail;
				}
				tail = node;
				count++;
			}

			public void AddFirst(T data)
			{
				DoubleNode<T> node = new DoubleNode<T>(data);
				DoubleNode<T> temp = head;
				node.Next = temp;
				head = node;

				if (count == 0)
					tail = head;
				else
					temp.Previous = node;
				count++;
			}

			public bool Remove(T data)
			{
				DoubleNode<T> current = head;

				while (current != null)
				{
					if (current.Data.Equals(data))
					{
						break;
					}
					current = current.Next;
				}
				if (current != null)
				{
					if (current.Next != null)
					{
						current.Previous.Next = current.Previous;
					}
					else
					{
						tail = current.Previous;
					}

					if (current.Previous != null)
					{
						current.Previous.Next = current.Next;
					}
					else
					{
						head = current.Next;
					}
					count--;
					return true;
				}
				return false;
			}

			public void Clear()
			{
				head = null;
				tail = null;
				count = 0;
			}

			IEnumerator IEnumerable.GetEnumerator()
			{
				return ((IEnumerable)this).GetEnumerator();
			}

			IEnumerator<T> IEnumerable<T>.GetEnumerator()
			{
				DoubleNode<T> current = head;

				while (current != null)
				{
					yield return current.Data;
					current = current.Next;
				}
			}

			public IEnumerable<T> BackEnumerator()
			{
				DoubleNode<T> current = tail;

				while (current != null)
				{
					yield return current.Data;
					current = current.Previous;
				}
			}
		}

		static void Main(string[] args)
		{
			int tmp;
			bool check;
			DoubleLinkedList<string> lst = new DoubleLinkedList<string>();

			Console.WriteLine("Реализацiя завдання з двозв'язним списком:");
			do
			{
				Console.WriteLine("Введiть кiлькiсть елементiв для додавання в список:");
				if (int.TryParse(Console.ReadLine(), out tmp))
					check = false;
				else
					check = true;

			} while (check);

			for (int i = 0; i < tmp; i++)
			{
				Console.Write("Введiть елемент -> ");
				lst.AddLast(Console.ReadLine());
			}

			foreach (var item in lst)
			{
				Console.WriteLine(item);
			}

			while (true)
			{
				Console.WriteLine("Основнi функцii з двозв'язним списком:\n1. Додати в початок\n2. Додати в кiнець\n3. Видалити\n4. Очистити список");
				int task = Convert.ToInt32(Console.ReadLine());

				if (task == 1)
				{
					Console.Write("Введiть елемент -> ");
					lst.AddFirst(Console.ReadLine());

					foreach (var item in lst)
					{
						Console.WriteLine(item);
					}
				}
				else if (task == 2)
				{
					Console.Write("Введiть елемент -> ");
					lst.AddLast(Console.ReadLine());

					foreach (var item in lst)
					{
						Console.WriteLine(item);
					}
				}
				else if (task == 3)
				{
					Console.WriteLine("Введiть елемент для видалення:");
					lst.Remove(Console.ReadLine());
					Console.WriteLine("-------------");
					foreach (var item in lst)
					{
						Console.WriteLine(item);
					}
				}
				else if (task == 4)
					lst.Clear();
				else
					Console.WriteLine("Помилка");
			}
		}
	}
}
