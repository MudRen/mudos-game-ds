#include <ansi.h>
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name(HIR"�i�f�i��"NOR, ({ "coca cola","cola" }) );
        set_weight(300);
        if( clonep() )
        	set_default_object(__FILE__);
        else
        {
    		set("long", "�o�O�@���Q�����w�諸���ơA��(drink)�F�i�H�Ѵ��ɥR��O�C\n");
      		set("unit", "��");
		set("drink_msg","$N���_�@��$n�A�B�P�B�P�a�ܤF�X�f�C\n");
		set("finish_drink_msg","$N�N�l�U��$n�ܥ��F�C\n");
     	}
     	set("value", 20);
        set("heal_ap",5);
        set("heal_mp",4);
	set("water_remaining", 3);
	setup();
}
