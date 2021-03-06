#include <ansi.h>
inherit ITEM;

string *color = ({ MAG,	HIG, HIY, HIW, HIC, HIR, });
string *carname = ({
	HIY+"伊克一型 "+NOR,
	HIW+"藍特 "+NOR,
	HIG+"綠閃光 "+NOR,
	HIW+"TERANNER 3000 "+NOR,
	HIB+"海洋 "+NOR,
	HIC+"BORD II "+NOR,
	HIY+"洛瓦十二 "+NOR,
});

void create()
{
	string name;
	name=carname[random(sizeof(carname))];
	set_name(HIR"小型噴射引擎車"NOR+name,({"new car","car"}));
	set("long","這是由美薩公司開發的車種。\n");
	set("no_get",1);
	set("no_drop",1);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","台");
		set("value",100);
	}
	setup();
}

void init()
{
	add_action("do_drive","drive");
	add_action("do_disdrive","disdrive");
}

int do_drive()
{
	object me=this_player();
	int d;
	if( (int)me->query_skill("drive") )d=(int)me->query_skill("drive");
	if( me->query_temp("marks/drive") )return notify_fail("你已經在車內。\n");
	if( d<30 || !d )return notify_fail("你的駕駛技術不足，不能駕駛！\n");
	message_vision("$N進入了"+this_object()->name()+"的駕駛座。\n",me);
	this_player()->set_temp("marks/drive",1);
	this_player()->add_temp("apply/short",({ me->short()+HIY"(正駕駛著"NOR+this_object()->name()+HIY")"NOR}));
	this_object()->move(me);
	return 1;
}

int do_disdrive()
{
	object me;
	me=this_player();
	if( !me->query_temp("marks/drive") )return notify_fail("你不在駕駛座上。\n");
	message_vision("$N離開了"+this_object()->name()+"。\n",me);
	me->delete_temp("marks/drive");
	me->delete_temp("apply/short");
	this_object()->move(environment(me));
	return 1;
}
