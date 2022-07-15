using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp
{
	class Program
	{
		static string[] cities = {
			"Київ",
			"Житомир",
			"Новоград-Волинський",
			"Рівне",
			"Луцьк",
			"Бердичів",
			"Вінниця",
			"Хмельницький",
			"Тернопіль",
			"Шепетівка",
			"Біла церква",
			"Умань",
			"Черкаси",
			"Кременчуг",
			"Полтава",
			"Харків",
			"Прилуки",
			"Суми",
			"Миргород"
		};

		static void Main(string[] args)
		{
			Console.InputEncoding = Encoding.Unicode;
			Console.OutputEncoding = Encoding.Unicode;
			int[,] matrix=new int[20,20];
			matrix[0, 1] = 135;
			matrix[1, 2] = 80;
			matrix[2, 3] = 100;
			matrix[3, 4] = 68;
			matrix[1, 5] = 38;
			matrix[5, 6] = 73;
			matrix[6, 7] = 110;
			matrix[7, 8] = 104;
			matrix[1, 9] = 115;
			matrix[0, 10] = 78;
			matrix[10, 11] = 115;
			matrix[10, 12] = 146;
			matrix[12, 13] = 105;
			matrix[10, 14] = 181;
			matrix[14, 15] = 130;
			matrix[0, 16] = 128;
			matrix[16, 17] = 175;
			matrix[16, 18] = 109;

			int distance = 0;
			string beginning = "";
			int j = 0;
			bool[] visitedDFS = new bool[matrix.GetLength(0)];
			bool[] visitedBFS = new bool[matrix.GetLength(0)];
			Console.WriteLine("DFS");
			DFS(j,matrix, visitedDFS, distance, beginning);
			Console.WriteLine("\n");
			Console.WriteLine("BFS");
			BFS(j, matrix, visitedBFS);
			Console.ReadKey();
		}
		static void DFS(int j, int[,] graph, bool[] visited, int distance = 0, string beginning = "")
		{
			if (beginning == "")
				beginning = cities[j];
			visited[j] = true;
			for (int i = 0; i < graph.GetLength(0); i++)
			{
				if (graph[j, i] != 0 && visited[i] != true)
				{
					int finaldistance = distance + graph[j, i];
					Console.WriteLine(beginning + " -> " + cities[i] + ": " + finaldistance + "км");
					DFS(i, graph, visited, finaldistance, beginning);
				}
			}
		}
		static void BFS(int j, int[,] graph, bool[] visited)
		{
			int[] distance = new int[graph.GetLength(0)];
			string beginning = cities[j];
			Queue<int> q = new Queue<int>();
			visited[j] = true;
			q.Enqueue(j);
			while (q.Count != 0)
			{
				j = q.Dequeue();
				for (int i = 0; i < graph.GetLength(0); i++)
				{
					if (graph[j, i] != 0 && visited[i] != true)
					{
						visited[i] = true;
						q.Enqueue(i);
						distance[i] = distance[j] + graph[j, i];
						Console.WriteLine(beginning + " -> " + cities[i] + ": " + distance[i] + "км");
					}
				}
			}
		}
	}
}

