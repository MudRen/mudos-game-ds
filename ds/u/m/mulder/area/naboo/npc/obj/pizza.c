inherit ITEM;
#include <ansi.h>
inherit F_FOOD;

void create()
{
        set_name(HIR "����"NOR, ({ "pizza" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�o�O�Ѥ@�ӤQ���i�f���F�F�A�A������ı�a�y�U\�\\�h�f�������\n");
                set("unit", "��");
	     set("value", 200);       
                set("heal_hp",50);
	set("heal_ap", 50);
        	    set("food_remaining", 5);
       }
}