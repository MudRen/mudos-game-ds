#include <armor.h>

#include <ansi.h>

inherit CLOTH;

void create()

{

        set_name(HIC"�үů���"NOR ,({ "level D cloth","cloth" }) );

        set_weight(900);

        if( clonep() )

                set_default_object(__FILE__);

        else {

 set("long",@LONG

�Ѭɯ��L�̩Ҭ諸��A�T

LONG

     );

        set("unit", "��");

        set("value",2000);

        set("material", "cold");

        set("armor_prop/shield",1);

        

        set("armor_prop/armor", 15);

        }

        setup();

}
