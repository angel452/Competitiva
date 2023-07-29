from collections import defaultdict #Map

# El grafo se representa como una matriz de adyacencia
class Graph():
    #---------- CONSTRUCTOR ----------------------
    def __init__(self, _vertices):
        self.vertices = _vertices #numero de veritices
        self.grafo = defaultdict(list) #aqui guardamos el grafo

    #---------- FUNCIONES ----------------------  
    #Añadir arista a un grafo
    def appendEdge(self, aux1, aux2):
        self.grafo[aux1].append(aux2)

    #Busqueda en profundidad
    def dfsAlgorithm(self, v, visitVertex):
        visitVertex[v] = True

        print(v, end= ' ')

        #Recursividad para los vertices adyacentes
        for i in self.grafo[v]:
            if not visitVertex[i]:
                self.dfsAlgorithm(i, visitVertex)
    
    #Busqueda en profundidad
    def dfsAlgorithmPila(self, v, visitVertex, stack):
        visitVertex[v] = True

        #Recursividad para los vertices adyacentes
        for i in self.grafo[v]:
            if not visitVertex[i]:
                self.dfsAlgorithmPila(i, visitVertex, stack)
        stack = stack.append(v)

    # Creacion de la inversa de la matriz
    def invMatrix(self):
        newGraph = Graph(self.vertices)

        #recorrer todos los vertices:
        for i in self.grafo:
            for j in self.grafo[i]:
                newGraph.appendEdge(j, i)

        return newGraph

    def kosarajuAlgorithm(self):
        stack = []
        visitVertex = [False] * (self.vertices) #marcamos como no visitados a todos los vertices

        # PRIMERA RONDA: llenamos la pila de nodos visitados y el STACK
        for i in range(self.vertices):
            if not visitVertex[i]:
                self.dfsAlgorithmPila(i, visitVertex, stack)

        invGraph = self.invMatrix() #creamos su grafo transpuesta/inversa
        visitVertex = [False] * (self.vertices) #marcamos como no visitados a todos los vertices

        #SEGUNDA RONDA: recorremos el stack creando los SCC
        print("------------- Grupos ----------------- ")
        while stack:
            aux1 = stack.pop()
            if not visitVertex[aux1]:
                invGraph.dfsAlgorithm(aux1, visitVertex)
                print(" ")
        print("--------------------------------------- ")

############################ MAIN #######################################
grafo = Graph(8)

#Creamos aristas:
# A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7
grafo.appendEdge(0,1)
grafo.appendEdge(1,2)
grafo.appendEdge(2,0)
grafo.appendEdge(3,1)
grafo.appendEdge(3,2)
grafo.appendEdge(3,5)
grafo.appendEdge(4,2)
grafo.appendEdge(4,6)
grafo.appendEdge(5,3)
grafo.appendEdge(5,4)
grafo.appendEdge(5,7)
grafo.appendEdge(6,4)
grafo.appendEdge(6,7)
grafo.appendEdge(7,6)

#Ejecutamos Algoritmo kosara
grafo.kosarajuAlgorithm()