#include <armor.h>
#include <ansi.h>
inherit MASK;

void create()
{
        set_name( "��v�Q����" ,({ "moon-shadow mask","mask" }) );
        set("long",@LONG
�o�O�@���観��������������A���������V��@�몺�꯾��n�ۤϡA
���K�F�X���޲����^��C
LONG
);
        set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
	        set("material","fur");
	        set("unit","��");
	        set("value",3000);
	        set("limit_int",50);
        }
        set("armor_prop/str", 1);
        set("armor_prop/int", 1);
        set("armor_prop/armor",5);
        setup();
}
