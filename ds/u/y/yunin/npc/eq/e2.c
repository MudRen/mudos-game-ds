#include <armor.h>

#include <ansi.h>

inherit CLOTH;

void create()

{

        set_name(HIR"��"HIW"�y"HIY"�@"HIC"�T"NOR ,({ "more cloth","cloth" }) );

        set_weight(1000);

        if( clonep() )

                set_default_object(__FILE__);

        else {

 set("long",@LONG

�o�O�ǻ����Щ]�l�b�Q����~�Y�������L���@�T�C

LONG

     );

                set("unit", "��");

                set("value",500);

                set("material", "steel");

                set("armor_prop/shield",2);

                set("armor_prop/con",3);

                set("armor_prop/armor", 23);

        }

        setup();

}
