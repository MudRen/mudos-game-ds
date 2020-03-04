// 書本
inherit ITEM;

void create()
{
	set_name("龍蝦烹飪食譜",({"book12345"}) );
	set("long","一本書耶。\n");
	set_weight(300);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("value",250);
		set("unit","本");
	}
	set("bookauthor","luky");	// 書本作者
	set("bookkind",({ "all","food","龍蝦","食譜","烹飪","食物" }));	// 書本種類
	set("bookno",12345);	// 書本號碼
	setup();
}
