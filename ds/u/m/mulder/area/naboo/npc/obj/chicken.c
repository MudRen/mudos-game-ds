inherit ITEM;
#include <ansi.h>
inherit F_FOOD;

void create()
{
        set_name(YEL "�N��"NOR, ({"fire chicken","chicken"}) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�o�@���N�o�n���������A�A������ı�a�y�U\�\\�h�f�������\n");
                set("unit", "��");
	set("value", 200);       
                set("heal_hp",15);
	set("heal_ap", 15);
        	set("food_remaining", 5);
       }
}