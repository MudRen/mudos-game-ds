// An example book
inherit ITEM;
inherit F_UNIQUE;
void create()
{
set_name("程式設計大全",({"computer book","book"}));
set_weight(100);
set("unit","本");
set("long",@NOTE

  這是一本內容豐富的電腦書籍。

NOTE
);
set("replica_ob","/d/wiz/npc/game");	//配合F_UNIQUE使用,當此物件已經
					//產生過時,指定的檔案會取代此物件
setup();
}
