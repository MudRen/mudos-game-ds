#include <ansi.h>

inherit ITEM;
inherit F_PILL;

int create()
{
        set_name("���ͤ��Ѥ�", ({ "immortality's pill","pill" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("base_unit", "��");
                set("base_value", 100);
                set("base_weight", 100);
                set("food_stuff", 10);
                set("long", "�ǻ��������ͤ��Ѥ��A�Y(eating)�F�����|������@�ΡC\n");
        }
        setup();
}

void init()
{
	add_action("do_eat","eat");
}

int do_eat(string arg)
{
	object me=this_player();
	if( arg != "immortality's pill" && arg!="pill" )
		return 0;
//	me->supplement_stat("kee", 100);	// At ��_��
	me->receive_heal("hp",100);		// Ds ��_HP

	message_vision("$N�Y�U�F�@��$n�C\n",me,this_object());
	if( this_object()->query("fly_speed") )
	{
		message_vision(HIW"$N���ƤF�_�ӡA�H�Y���t�����W�ѪšI\n"NOR,me);
		me->set_temp("fly_speed",this_object()->query("fly_speed"));
                me->set_temp("fly_long",120000);
                if( me->query_temp("fly_time") ) me->delete_temp("fly_time");
		me->move(__DIR__"sky.c");
	}

        destruct(this_object());
	return 1;
}
