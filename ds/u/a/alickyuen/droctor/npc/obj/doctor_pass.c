// ���|�H��
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(YEL"�y���z"NOR+"����ҷ�", ({ "passport of doctor","passport" }) );
	set_weight(600);
	if( clonep() ) set_default_object(__FILE__);
	else
	{
		set("value",0);
		set("no_drop",1);
		set("no_sell",1);
		set("no_sac",1);
		set("unit","��");
set("no_give",1);
                set("long",
                        "�@�������ҷӡA���ҷӱM����ͬ��]�A�H�K�ҩ�����ͨ����C\n");
	}
	setup();
}

int query_autoload() { return 1; } //save_item

void init()
{
object obj, me;
me=this_player();
obj=this_object();
if(me->query("level")<9) 
obj->set_name(YEL"�y���z"NOR+"����ҷ�", ({ "passport of doctor","passport" }) );
if(me->query("level")<19 && me->query("level")>10) 
obj->set_name(YEL"�y�����z"NOR+"����ҷ�", ({ "passport of doctor","passport" }) );
if(me->query("level")<29 && me->query("level")>20) 
obj->set_name(YEL"�y�������z"NOR+"����ҷ�", ({ "passport of doctor","passport" }) );
if(me->query("level")<39 && me->query("level")>30) 
obj->set_name(YEL"�y���������z"NOR+"����ҷ�", ({ "passport of doctor","passport" }) );
if(me->query("level")<49 && me->query("level")>30) 
obj->set_name(YEL"�y�����������z"NOR+"����ҷ�", ({ "passport of doctor","passport" }) );
if(me->query("level")==50) 
obj->set_name(YEL"�y���z"NOR+"����ҷ�", ({ "passport of doctor","passport" }) );
}

                