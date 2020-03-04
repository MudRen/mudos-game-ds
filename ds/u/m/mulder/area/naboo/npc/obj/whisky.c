#include <ansi.h>
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name(YEL"�¤h��"NOR, ({ "whisky" }) );
        set_weight(1000);
        if( clonep() )
        	set_default_object(__FILE__);
        else
        {
    		set("long", "�o�O�@�~�Q�����s�a�w�諸���ơA��(drink)�F�|�^�_�ܦh��O�C\n");
      		set("unit", "�~");
		set("drink_msg","$N���_�@�~$n�A�B�P�B�P�a�ܤF�X�f�C\n");
		set("finish_drink_msg","$N��l�U��$n�ܥ��F�C\n");
     	    	set("value",500);
        		set("heal_ap",50);
		set("heal_hp",50);
        		set("heal_mp",50);
	    	set("water_remaining", 10);
}
}	
void init()
{
	add_action("do_drink", "drink");
}

int do_drink(string arg)
{
	object me;
	if( !this_object() ) return 0;
	if( !this_object()->id(arg) ) return 0;
	me=this_player();
    	if(me->query("age")<18)
	{return notify_fail(HIR"�p�Ĥl�O�����ӳܰs���C\n"NOR);
	}
	else return ::do_drink(arg);
}
