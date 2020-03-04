inherit ITEM;

void create()
{
	set_name("亞連藤蔓",({"yalen cirri","cirri"}) );
	set_weight(500);
	set("long","這是一條亞連樹藤蔓，多半被用來套補動物(catch)。\n");
	if(clonep() )
		set_default_object(__FILE__);
	else {
	set("value",1);
	set("material","plant");
	set("volume",1);
	}
	setup();
}

void init()
{
	add_action("do_catch","catch");
}

int do_catch(string arg)
{
	object me,ob;
	me=this_player();
	if(!arg || arg!="骨名" )
		return notify_fail("亞連藤蔓只能用來補捉骨名。\n");
	if(!objectp(ob=present("gu name",environment(me)) ) )
		return notify_fail("這裡沒有骨名這隻動物。\n");
	if(query("catch_ok") )
		return notify_fail("你已經捉到骨名了。\n");
	message_vision("$N利用身上的一條藤蔓，順利捉到骨名。\n",me);
	set("catch_ok",1);
	destruct(ob);
	return 1;
}