#include <armor.h>

#include <ansi.h>

inherit CLOTH;

void create()

{

        set_name(HIR"修羅之衣〥"NOR ,({ "shu lo cloth","cloth" }) );

        set_weight(1000);

        if( clonep() )

                set_default_object(__FILE__);

        else {

 set("long",@LONG
四大塔王之一的燕非彥使用的防具。
LONG

     );

                set("unit", "件");

                set("value",5000);

                set("material", "cold");
               

                set("armor_prop/con",1);

                set("armor_prop/armor", 23);

        }

        setup();

}

