#include <ansi.h>
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name(HIC"���G���v"NOR, ({ "fruit punch","punch" }) );
        set_weight(400);
        if( clonep() )
        	set_default_object(__FILE__);
        else
        {
    		set("long", "�o�O�@�M�Ѥ֫w�y�����~�A��(drink)�F�i�H�Ѵ��ɥR��O�C\n");
      		set("unit", "�M");
		set("drink_msg","$N���_�@�M$n�A�B�P�B�P�a�ܤF�X�f�C\n");
		set("finish_drink_msg","$N�N�l�U��$n�ܥ��F�C\n");
     	}
     	set("value", 50);
        set("heal_ap",15);
        set("heal_mp",14);
	set("water_remaining", 4);
	setup();
}
