// 書本
inherit ITEM;

void create()
{
	set_name("我曾經倉皇失措的愛著妳",({"book33333"}) );
	set("long","一本書耶。\n");
	set_weight(300);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("value",250);
		set("unit","本");
	}
	set("bookauthor","shengsan");	// 書本作者
	set("bookkind", ({ "all","文學","散文" }));	// 書本種類
	set("bookno",33333);	// 書本號碼
	setup();
}
