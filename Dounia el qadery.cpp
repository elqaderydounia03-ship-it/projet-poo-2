#include<iostream>
#include<string>
using namespace std;

class livre{
	private:
		int id;
		string titre;
		string auteur;
		float prix;
		bool disponible;
		
		public:
			livre(){
				id=0;
				titre="";
				auteur="";
				prix=0;
				disponible=true;
			}
			livre(int i , string t, string a ,float p, bool d = true){
				id=i;
				titre =t;
				auteur=a;
				prix=p;
				disponible=d;
			}
			livre(const livre & L){
				id=L.id;
				titre=L.titre;
				auteur=L.auteur;
				prix=L.prix;
				disponible=L.disponible;
			}
			~livre(){	
			}
			void afficher(){
				cout<<"\n|d:"<<id<<endl;
				cout<<"titre:"<<titre<<endl;
				cout<<"auteur:"<<auteur<<endl;
				cout<<"prix:"<<prix<<endl;
				if(disponible)
				cout<<"disponible"<<endl;
				else
				cout<<"non disponible"<<endl;
			}
			void modifierprix(float nvprix){
				prix = nvprix;
			}
			bool estcher(){
				return prix>200;
			}
			int getid(){
				return id;
			}
			void supprimer (){
				disponible=false;
			}
};
int main(){
	livre bibliotheque[100];
	int nb=0;
	
	int choix;
	do {
		cout<<"\n======menu====="<<endl;
		cout<<"1.ajouter livre"<<endl;
		cout<<"2.afficher livre"<<endl;
		cout<<"3.recherche livre"<<endl;
		cout<<"4.supprimer livre"<<endl;
		cout<<"5.quitter livre"<<endl;
		cout<<"choix:";
		cin>>choix;
		
		switch (choix){
			case 1:{
				int id;
				string titre,auteur;
				float prix;
				
				cout<<"id";
				cin>>id;
				
				cin.ignore();
				cout <<"titre:";
				getline(cin,titre);
				cout<<"auteur:";
				getline(cin,auteur);
				cout<<"prix :";
				cin>>prix;
				bibliotheque[nb]=livre(id,titre,auteur,prix,true);
				nb++;
				cout<<"livre ajoute !"<<endl;
				break;
			}
			case 2:{
				for(int i =0;i<nb;i++){
					bibliotheque[i].afficher();
				}
				break;
			}
			case3:{
				int idrecherche;
				bool trouve =false;
				cout<"donner id";
				cin>>idrecherche;
				for(int i=0;i>nb;i++){
					if( bibliotheque[i].getid()==idrecherche){
						bibliotheque[i].afficher();
						trouve=true;
					}
				}
				if(trouve)
				cout<<"livre introuvable!"<<endl;
				break;
			}
			case 4:{
				int idsupp;
				cout<<"id a supprimer:";
				cin>>idsupp;
				for(int i=0;i<nb;i++){
				if(bibliotheque[i].getid()==idsupp){
					bibliotheque[i].supprimer();
					cout<<"suppression logique effectue!"<<endl;
				}
			}
				break;
			}
			case 5:
				cout<<"fin programme."<<endl;
				break;
				default:
					cout<<"choix invalide !"<<endl;
			}
		}while (choix!=5);
		
	
	return 0;
}
	
