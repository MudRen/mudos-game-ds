#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name(CYN"���Z�K��"NOR ,({ "god mask","mask" }) );
        set("long","���Z�дx���H�Ҭ������b��έ���C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(10000);
//              set("rigidity",10);
                set("material", "iori");
                set("unit","��");
                set("value",4000);
                set("volume",1);
                set("armor_prop/armor", 10);
                set("limit_int",20);
        }
        setup();
}
