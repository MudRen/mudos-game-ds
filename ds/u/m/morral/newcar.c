#include <ansi.h>
inherit ITEM;

string *color = ({ MAG,	HIG, HIY, HIW, HIC, HIR, });
string *carname = ({
	HIY+"��J�@�� "+NOR,
	HIW+"�ůS "+NOR,
	HIG+"��{�� "+NOR,
	HIW+"TERANNER 3000 "+NOR,
	HIB+"���v "+NOR,
	HIC+"BORD II "+NOR,
	HIY+"���ˤQ�G "+NOR,
});

void create()
{
	string name;
	name=carname[random(sizeof(carname))];
	set_name(HIR"�p���Q�g������"NOR+name,({"new car","car"}));
	set("long","�o�O�Ѭ��Ĥ��q�}�o�����ءC\n");
	set("no_get",1);
	set("no_drop",1);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","�x");
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
	if( me->query_temp("marks/drive") )return notify_fail("�A�w�g�b�����C\n");
	if( d<30 || !d )return notify_fail("�A���r�p�޳N�����A����r�p�I\n");
	message_vision("$N�i�J�F"+this_object()->name()+"���r�p�y�C\n",me);
	this_player()->set_temp("marks/drive",1);
	this_player()->add_temp("apply/short",({ me->short()+HIY"(���r�p��"NOR+this_object()->name()+HIY")"NOR}));
	this_object()->move(me);
	return 1;
}

int do_disdrive()
{
	object me;
	me=this_player();
	if( !me->query_temp("marks/drive") )return notify_fail("�A���b�r�p�y�W�C\n");
	message_vision("$N���}�F"+this_object()->name()+"�C\n",me);
	me->delete_temp("marks/drive");
	me->delete_temp("apply/short");
	this_object()->move(environment(me));
	return 1;
}
