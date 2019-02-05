#include <stdio.h>
#include <stdlib.h>


struct Node //Node ismide yapýmýzý oluþturuyoruz.
{
	int data;//Tutulacak veri için deðiþken 
	struct Node*next;//Sonraki referans için alan 
	struct Node*prev;//Önceki referans için alan
};


void sondanSil(struct Node *q)//Verilen struct ýn son düðümünü siler.
{
	struct Node* last_Node = q;//SON NODE TUTACAK YAPI OLUÞTURUYORUZ
	while (last_Node->next != NULL)//DÖNGÜYE ALIP SON ELEMANA KADAR DÖNDÜRÜP SON ELEMANI BULUP LAST A ATIYORUZ.
	{
		last_Node = last_Node->next;
	}

	last_Node->prev->next = NULL;
	free(last_Node);
}

void bastanSil(struct Node **q)//baþtan eleman siler
{
	struct Node *tmp = *q;
	*q = tmp->next;
	tmp->next->prev = NULL;
	free(tmp);
}

void ortaSil(struct Node *q,int key)//içerisineki dataya göre silme iþlemi yapar
{

	
     struct Node *tmp = q;
	 while (tmp->data != key)//DÖNGÜYE ALIP -VERÝLEN ELEMANA AYÝT OLANI BULUR
	 {
		 tmp = tmp->next;
	 }
	 if (tmp->data ==key)//SÝLME ÝÞLEMÝ ÝÇÝN SONKEZ KEY OLUÞUYORMU DÝYEK ONTROL EDÝYORUZ.
	 {
         tmp->prev->next = tmp->next;
	     tmp->next->prev = tmp->prev;
		 tmp->next = tmp->prev = NULL;
		 free(tmp);
	 }
}

void basaEkle(struct Node** head_Ref, int yeni_data)//listeye baþa veri ekleme
{
	struct Node* new_Node = (struct Node*)malloc(sizeof(struct Node));// Yeni bir node oluþturuyoruz.
	new_Node->data = yeni_data;//Oluþturduðumuz node a paramtere olarak gelen datayý atýyoruz.
	new_Node->next = (*head_Ref);	//verilen head ýn referansýný yeni node un next ine atýyoruz.
	new_Node->prev = NULL;//ilk baþta olacagý için ondan önce bir node olmayacak o yüzden null
	
	if ((*head_Ref) != NULL)
		(*head_Ref)->prev = new_Node;//yeni oluþturdugumuz nodedan sonraki node un pref ine yenisinin ref. ini atýyoruz

	*head_Ref = new_Node; //yeni node umuzu baþdaki olarak gösteriyoruz

}

void ortayaEkle(struct Node *q, int item, int key)// verilen keye göre ekleme yapar.
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
	if (prev_Node == NULL)//eðer verilen node boþ ise metod dan çýk
	{
		printf("Verilen Düðüm Boþ---(sonaEkle metodu)");
		return;// direk metodu bitirir ve çýkar
	}
	
	struct Node* new_Node = (struct Node*)malloc(sizeof(struct Node));//yeni node oluþturuyoruz
	new_Node->next = NULL;
	new_Node->data = yeni_data;//parametre olarak verilen datayý oluþturulan noda aktarýyoruz
	new_Node->next = prev_Node->next;//yeni node un next ine parametre verilen node un next indeki node u veriyoruz.
	prev_Node->next = new_Node;//parametre verilen node un next ini yeni node u atýyoruz
	new_Node->prev = prev_Node; //yeni oluþturdugumuz node a önceki olarak paramertereden gelen node u atýyoruz
	// yeni oluþturdugumuz node un next ini parametrenin next ini atýyoruz.
	
	//eðer yeni oluþtudugumuz node dan sonra node var ise prev yani önceki olarak new node u göster
	if (new_Node->next != NULL)
	{
	new_Node->next->prev = new_Node;
	}

}

void sonaEkle(struct Node** head_Ref, int yeni_data)//LÝSTEYE SONDAN VERÝ EKLEME
{
	struct Node* new_Node = (struct Node*)malloc(sizeof(struct Node));//YENÝ NODE OLUÞTURUYORUZ.
	struct Node* last_Node = *head_Ref;//SON NODE TUTACAK YAPI OLUÞTURUYORUZ

	new_Node->data = yeni_data;//PARAMETRE OLARAK VERÝLEN DATAYI YENÝ NODE ATIYORUZ.
	new_Node->next = NULL;//SONA EKLENECEGÝ ÝÇÝN NEXT ÝNÝ NULL YAPIYORUZ

	if (*head_Ref == NULL)//HEAD OLARAK VERÝLEN YAPI BOÞ ÝSE DÝREK EKLEYÝP METOD DAN ÇIKIYORUZ.
	{
		*head_Ref = new_Node;
		new_Node->prev = NULL;
		return;
	}

	while (last_Node->next != NULL)//DÖNGÜYE ALIP SON ELEMANA KADAR DÖNDÜRÜP SON ELEMANI BULUP LAST A ATIYORUZ.
	{
		last_Node = last_Node->next;
	}
	last_Node->next = new_Node;//SON ELAMANIN NEXT ÝNÝN YENÝ NODE UMUZ YAPIYORUZ.
	new_Node->prev = last_Node;//YENÝ ELEMANIMIZIN PREV YANÝ ÖNCEKÝ ELEMANINI SON ELEMAN YAPIYORUZ.
	return;


}

void ListeyiYazdýr(struct Node* node)//verilen node a göre listeye yazdýrma
{
	struct Node* last =node;//son node u için kaydýrmada kullanýlýcak yapý.

	printf("Bastan sona  :");
	while (node != NULL)// verilen node dan baþlayarak sona kadar olan node larý yazdýrýyor.
	{

		printf("%d,", node->data);
		last = node; //ters yazdýrmak için
		node = node->next;

	}

	printf("Sondan basa :");
	while (last != NULL)// yukardaki döngüden dolayý zaten sona gelen last ý baþa doðru giderek listeyi testen yazdýrýyorz
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



	////NOT: EÐER METOD DA ÇÝFT YILDIZ KULLANILDIYSA DÜÐÜM VERÝLÝRKEN '&' ÝLE KULLANILMALI.
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

	//ListeyiYazdýr(head);


	
	
}
