// 書本
inherit ITEM;

void create()
{
	set_name("天空的那一端",({"book11111"}) );
	set("long","這是一本書。書名為「天空的那一端」\n");
	set_weight(300);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("value",250);
		set("unit","本");
	}
	set("bookauthor","shengsan");	// 書本作者
	set("bookkind",({ "all","文學","散文" }));	// 書本種類
	set("bookno",11111);	// 書本號碼
	setup();
}
