inherit ITEM;
#include <ansi.h>
inherit F_FOOD;

void create()
{
        set_name(HIC "�ͤ�J�|"NOR, ({ "birthday cake","cake" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�o�O"HIC"�p"HIG"��"HIY"�z"NOR"���ͤ�J�|�A�]�����ѬO�L���ͤ�\n");
                set("unit", "��");
	    set("no_sac",1);
	    set("no_sell",1);	
	    set("value", 1000000);       
                set("heal_mp",100);
	    set("heal_hp", 100);
	    set("heal_ap", 100);
        	    set("food_remaining", 50);
       }
}