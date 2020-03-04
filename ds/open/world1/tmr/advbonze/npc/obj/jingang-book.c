#include <ansi.h>

inherit ITEM;

int do_learn(string arg);

void create()
{
	set_name("金剛羅漢陣法手卷",({"jingang plan book","book"}) );
	set_weight(80);
	set("long",@long
這是一本小手卷，上頭記載著「金剛羅漢陣法」的奧妙及修鍊方法。(learn)
long
);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","本");
		set("value",0);
	}
	setup();
}
void init()
{
	add_action("do_learn","learn");
}

int do_learn(string arg)
{
	object me=this_player();
	if(arg!="book")	return 0;
	if(me->is_fighting() || me->is_busy() )
                return notify_fail("你正忙著，沒空閱\讀書籍。\n");
	if( query("do_learn") )
		return notify_fail("這本手卷已經被翻破爛了，你無法從上面學到知識。\n");
	if(me->query_skill("jingang-plan") > 80)
		return notify_fail("你的「金剛羅漢陣法」已經到達一定火候，不用再閱\讀這本書了。\n");

	message_vision(HIC "$N細細閱\讀了手卷上的演練方法，似乎對金剛羅漢陣法又多熟練一些了。\n" NOR,me);
               me->add_skill("jingang-plan");
	set("do_learn",1);
return 1;
}
