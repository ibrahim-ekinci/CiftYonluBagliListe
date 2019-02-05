#include <stdio.h>
#include <stdlib.h>


struct Node //Node ismide yap�m�z� olu�turuyoruz.
{
	int data;//Tutulacak veri i�in de�i�ken 
	struct Node*next;//Sonraki referans i�in alan 
	struct Node*prev;//�nceki referans i�in alan
};


void sondanSil(struct Node *q)//Verilen struct �n son d���m�n� siler.
{
	struct Node* last_Node = q;//SON NODE TUTACAK YAPI OLU�TURUYORUZ
	while (last_Node->next != NULL)//D�NG�YE ALIP SON ELEMANA KADAR D�ND�R�P SON ELEMANI BULUP LAST A ATIYORUZ.
	{
		last_Node = last_Node->next;
	}

	last_Node->prev->next = NULL;
	free(last_Node);
}

void bastanSil(struct Node **q)//ba�tan eleman siler
{
	struct Node *tmp = *q;
	*q = tmp->next;
	tmp->next->prev = NULL;
	free(tmp);
}

void ortaSil(struct Node *q,int key)//i�erisineki dataya g�re silme i�lemi yapar
{

	
     struct Node *tmp = q;
	 while (tmp->data != key)//D�NG�YE ALIP -VER�LEN ELEMANA AY�T OLANI BULUR
	 {
		 tmp = tmp->next;
	 }
	 if (tmp->data ==key)//S�LME ��LEM� ���N SONKEZ KEY OLU�UYORMU D�YEK ONTROL ED�YORUZ.
	 {
         tmp->prev->next = tmp->next;
	     tmp->next->prev = tmp->prev;
		 tmp->next = tmp->prev = NULL;
		 free(tmp);
	 }
}

void basaEkle(struct Node** head_Ref, int yeni_data)//listeye ba�a veri ekleme
{
	struct Node* new_Node = (struct Node*)malloc(sizeof(struct Node));// Yeni bir node olu�turuyoruz.
	new_Node->data = yeni_data;//Olu�turdu�umuz node a paramtere olarak gelen datay� at�yoruz.
	new_Node->next = (*head_Ref);	//verilen head �n referans�n� yeni node un next ine at�yoruz.
	new_Node->prev = NULL;//ilk ba�ta olacag� i�in ondan �nce bir node olmayacak o y�zden null
	
	if ((*head_Ref) != NULL)
		(*head_Ref)->prev = new_Node;//yeni olu�turdugumuz nodedan sonraki node un pref ine yenisinin ref. ini at�yoruz

	*head_Ref = new_Node; //yeni node umuzu ba�daki olarak g�steriyoruz

}

void ortayaEkle(struct Node *q, int item, int key)// verilen keye g�re ekleme yapar.
{
	struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = item;
	struct Node *tmp = q;
	while (tmp->data!=key)
	{
		tmp = tmp->next;
	}
	
		ptr->next = tmp->next;
		ptr->prev = tmp;
		tmp->next = ptr;
		ptr->next->prev = ptr;
	
	
	
}

void onceEkle(struct Node* prev_Node, int yeni_data)//listeye ortadan ve ya saondan ekleme
{
	if (prev_Node == NULL)//e�er verilen node bo� ise metod dan ��k
	{
		printf("Verilen D���m Bo�---(sonaEkle metodu)");
		return;// direk metodu bitirir ve ��kar
	}
	
	struct Node* new_Node = (struct Node*)malloc(sizeof(struct Node));//yeni node olu�turuyoruz
	new_Node->next = NULL;
	new_Node->data = yeni_data;//parametre olarak verilen datay� olu�turulan noda aktar�yoruz
	new_Node->next = prev_Node->next;//yeni node un next ine parametre verilen node un next indeki node u veriyoruz.
	prev_Node->next = new_Node;//parametre verilen node un next ini yeni node u at�yoruz
	new_Node->prev = prev_Node; //yeni olu�turdugumuz node a �nceki olarak paramertereden gelen node u at�yoruz
	// yeni olu�turdugumuz node un next ini parametrenin next ini at�yoruz.
	
	//e�er yeni olu�tudugumuz node dan sonra node var ise prev yani �nceki olarak new node u g�ster
	if (new_Node->next != NULL)
	{
	new_Node->next->prev = new_Node;
	}

}

void sonaEkle(struct Node** head_Ref, int yeni_data)//L�STEYE SONDAN VER� EKLEME
{
	struct Node* new_Node = (struct Node*)malloc(sizeof(struct Node));//YEN� NODE OLU�TURUYORUZ.
	struct Node* last_Node = *head_Ref;//SON NODE TUTACAK YAPI OLU�TURUYORUZ

	new_Node->data = yeni_data;//PARAMETRE OLARAK VER�LEN DATAYI YEN� NODE ATIYORUZ.
	new_Node->next = NULL;//SONA EKLENECEG� ���N NEXT �N� NULL YAPIYORUZ

	if (*head_Ref == NULL)//HEAD OLARAK VER�LEN YAPI BO� �SE D�REK EKLEY�P METOD DAN �IKIYORUZ.
	{
		*head_Ref = new_Node;
		new_Node->prev = NULL;
		return;
	}

	while (last_Node->next != NULL)//D�NG�YE ALIP SON ELEMANA KADAR D�ND�R�P SON ELEMANI BULUP LAST A ATIYORUZ.
	{
		last_Node = last_Node->next;
	}
	last_Node->next = new_Node;//SON ELAMANIN NEXT �N�N YEN� NODE UMUZ YAPIYORUZ.
	new_Node->prev = last_Node;//YEN� ELEMANIMIZIN PREV YAN� �NCEK� ELEMANINI SON ELEMAN YAPIYORUZ.
	return;


}

void ListeyiYazd�r(struct Node* node)//verilen node a g�re listeye yazd�rma
{
	struct Node* last =node;//son node u i�in kayd�rmada kullan�l�cak yap�.

	printf("Bastan sona  :");
	while (node != NULL)// verilen node dan ba�layarak sona kadar olan node lar� yazd�r�yor.
	{

		printf("%d,", node->data);
		last = node; //ters yazd�rmak i�in
		node = node->next;

	}

	printf("Sondan basa :");
	while (last != NULL)// yukardaki d�ng�den dolay� zaten sona gelen last � ba�a do�ru giderek listeyi testen yazd�r�yorz
	{
		printf("%d,", last->data);
		last = last->prev;
	}
}

struct  komplex {
	int real;
	int img;
};
struct komplex topla(struct komplex a, struct komplex b)
{
	struct komplex k;
	k.real = a.real + b.real;
	k.img = a.img + b.img;
	return k;
}
 

int main()
{
	struct komplex a, b, c;
	printf( "Birinci komplex sayinin real degerini girin :" );
	scanf_s("%d",&a.real);
	printf("Birinci komplex sayinin img degerini girin :");
	scanf_s("%d", &a.img);

	printf("ikinci komplex sayinin real degerini girin :");
	scanf_s("%d", &b.real);
	printf("ikinci komplex sayinin img degerini girin :");
	scanf_s("%d", &b.img);


	printf("birinci komplex sayi %d%d\n",a.real,a.img);
	printf("ikinci komplex sayi %d%d\n", b.real, b.img);
	c = topla(a, b);
	printf("Sonuc : %d% di", c.real, c.img);
	getche();



	////NOT: E�ER METOD DA ��FT YILDIZ KULLANILDIYSA D���M VER�L�RKEN '&' �LE KULLANILMALI.
	//struct Node* head = NULL;

	//basaEkle(&head, 7);
	//basaEkle(&head, 1);
	//basaEkle(&head, 4);

	////onceEkle(head->next, 8);

	//ortayaEkle(head, 6, 1);
	////sondanSil(head);
	////bastanSil(&head);
	////ortaSil(head,1);
	//printf("Olusturulan node lar : ");

	//ListeyiYazd�r(head);


	
	
}
