//u/c/chiaa/obj/eq/hon len_belt.c
#include <armor.h>
#include <ansi.h>
inherit WAIST;

void create()
{
        set_name(HIR"����"HIB"�y�a"NOR,({"hon len belt","belt"}) );
        set("long","�@���N�_�Ӭ۷�X�n,���A�Pı�ܵΪA���y�a�C\n");

        if (clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(200);
                set("unit","��");        
                set("material","fur");
                set("armor_prop/armor",6);
                set("value", 200);
        }
        setup();
}
