#include <iostream>
#include <vector>
#include <map>

using namespace std;

// -------------- DEFINE -----------------
#define ll long long
 
// ----------- VARIABLES GLOBALES -----------
const int maxn=1e5+10;
const int LG=21+5;
int par[LG][maxn];
int h[maxn];
int pd[maxn];

vector<int> adj[maxn];
map<int,int> mp[maxn];

int dp[maxn];
int suf[maxn];
int cnt;

// ------------ FUNCIONES ----------------------
void seeVector(vector<int> vec)
{
    for (int i = 0; i < 10; i++) 
    {
        cout << vec[i] << " ";
    }
}

void dfs(int s,int pr) 
{
    par[0][s] = pr;
    for(int i=1;i<LG;i++)
    {
        if(par[i-1][s] == -1)
        {
            par[i][s] = -1;
        } 
        else 
        {
            par[i][s] = par[i-1][ par[i-1][s] ];
        }
    }

    cout << "--- PAR ---" << endl;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout << par[i][j] << " ";
        }
        cout <<  endl;
    }

    for(int i=0;i<adj[s].size();i++) // navega por el arbol como si fuera un arbol normal 
    {
        cout << "----- Evaluar recursividad ------ " << endl;
        cout << i << " -> " << adj[s].size() << endl;
        cout << "-------------------------------- " << endl;
        if(adj[s][i]!=pr) // si NO es un nodo hoja. Esto seguira llamando al dfs hasta que el siguiente nodo le haga regresar al anterior, el anterior es pr. cuando pr es -1 significa que es un padre
        {
            cout << adj[s][i] << " = "<<  h[s]+1 << endl;
            h[ adj[s][i] ] = h[s]+1;

            for (int i = 0; i < 10; i++) 
            {
                cout << h[i] << " ";
            }
            cout << endl;

            dfs(adj[s][i],s);
        }
    }
    return ; // significa que llego a un nodo hoja
}

void ans(int s,int pr)
{
	for(int i=0;i<adj[s].size();i++)
    {
        cout << i << " -> " << adj[s].size() << endl;
		if(adj[s][i]!=pr) //el nuevo nodo es distinto al ya evaluado?
        {
            cout << "Recursividad!!!" << endl;
            ans(adj[s][i],s);

            dp[ mp[s][adj[s][i]] ] += pd[adj[s][i]]; // si pasa aca es que es un nodo hoja o final
            pd[s] += pd[adj[s][i]];

            cout << "DP dentro if:" << endl;
            for(int i = 0; i < 10; i++)
            {
                cout << dp[i] << " ";
            }
            cout << endl;
            cout << "PD dentro if:" << endl;
            for(int i = 0; i < 10; i++)
            {
                cout << pd[i] << " ";
            }
            cout << endl;

	    }
    }
	pd[s] = pd[s] + suf[s];

    cout << "PD:" << endl;  
    for(int i = 0; i < 10; i++)
    {
        cout << pd[i] << " ";
    }
    cout << endl;

	cerr << "valor: " << pd[s] << " En la posicion " << s << " " <<endl;
	return ;
}

int lca(int u ,int v)
{
    cout << " ---- LCA ---- " << endl;
    if(h[u] > h[v]) // V siempre debe tener al mayor
    {
        cout << "-- swap --" << endl;
        swap(u , v);
    }
                
    for(int i=LG-1;i>=0;--i) if(par[i][v] != -1) // v representa el nodo de llegada
    {
        cout << "Fila (i): "  << i << endl;
        cout << par[i][v] << " >= " << h[u] << " ?" << endl;
        if( h[ par[i][v] ] >= h[u] ) // verifica si el nodo U esta mas arriba que V creo. Si no entra en el condicional, busca uno mas arriba de llegada en el PAR
        {
            cout << " v =  " <<  par[i][v] << endl;
            v = par[i][v]; // creo que reemplazamos por v el LCA()
        }        
    }

    if(u == v)  // Si coinciden ...
    {
        return v;
    }

    cout << "Caso adicional" << endl;
    for(int i=LG-1; i+1; i--)
    {
        if(par[i][v] != par[i][u])
        {
            cout << par[i][v]<< " != " << par[i][u] << endl;
            u = par[i][u] , v = par[i][v];
        }
    }

    return par[0][v]; // ultimo caso, donde debolvemos la primera fila      
}

// #################### MAIN ###########################
int main(){
	int n;cin>>n;
	for(int i=0; i<n-1; i++)
    {
		int m;
		int k;
		cin>>m>>k;
		adj[m].push_back(k);
		adj[k].push_back(m);
		mp[m][k]=i+1;
		mp[k][m]=i+1;
	}

    /*
    cout << " ------- Matriz mp ------ " << endl;
    for (ll i = 0; i < 6; i++) 
    {
        for (ll j = 0; j < 6; j++) 
        {
            cout << mp[i][j] << " ";
        }
        cout << endl;
    }

    cout << " ------- Matriz adj ------ " << endl;
    for (int i = 1; i < 10; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    */

	dfs(1,-1); // empieza el dfs en el nodo 1, indicando que es comienzo con -1

	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		int m;
		int j;
		cin>>m>>j;
		int w=lca(m,j);
		suf[w] = suf[w] - 2; // -2 porque luego se le suma +1 por uno de los nodos
		suf[m]++; // el menor
		suf[j]++; // el mayor

        cout << "--- SUF ---" << endl;
        for (int i = 0; i < 10; i++) 
        {
            cout << suf[i] << " ";
        }
        cout << endl;
        cout << "------------------"<< endl;
	}

	cerr<<endl<<endl;

    cout << "ANS->" << endl;
	ans(1,-1); // misma entrada que el dfs

    cout << "RESPUESTA:" << endl;

	for(int i=1;i<n;i++)
    {
		cout<<dp[i]<<endl;
	}
}