#include <ansi.h>
inherit ITEM;

mixed *sortinv(object env);

void create()
{
	set_name(HIC"藍天測試儀(訊息)"NOR,({"tt2"}));
	set("long","這是一個水藍測試儀。\n");
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","個");
		set("value",9999);
	}
	setup();
}

void init()
{
	add_action("do_tt2","tt2");
}

int do_tt2()
{
	object me;
	me = this_player();

	message("world:world1:vision","古代室內外(所有環境)訊息測試!!!!\n",users());
	message("world:world2:vision","現代室內外(所有環境)訊息測試!!!!\n",users());
	message("world:world3:vision","未來室內外(所有環境)訊息測試!!!!\n",users());
	message("world:world1:outdoor:vision","古代室外(野外)訊息測試!!!!\n",users());
	message("world:world2:outdoor:vision","現代室外(野外)訊息測試!!!!\n",users());
	message("world:world3:outdoor:vision","未來室外(野外)訊息測試!!!!\n",users());
	

	return 1;
}
