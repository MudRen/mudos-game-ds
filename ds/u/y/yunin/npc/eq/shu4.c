#include <armor.h>

#include <ansi.h>

inherit CLOTH;

void create()

{

        set_name(HIR"��ù�����"NOR ,({ "shu lo cloth","cloth" }) );

        set_weight(1000);

        if( clonep() )

                set_default_object(__FILE__);

        else {

 set("long",@LONG
�|�j������@���P�D�ۨϥΪ�����C
LONG

     );

                set("unit", "��");

                set("value",5000);

                set("material", "cold");
               

                set("armor_prop/con",1);

                set("armor_prop/armor", 23);

        }

        setup();

}

