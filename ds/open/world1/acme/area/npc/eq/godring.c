#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(CYN"���Z�K��"NOR ,({ "god ring","ring" }) );
        set("long","���Z�дx���H�Ҭ��������p���٫��C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(8000);
//              set("rigidity",10);
//              set("material", "iori");
                set("unit","��");
                set("value",10000);
                set("armor_prop/armor", 1);
                set("armor_prop/int", 1);
                set("limit_int",20);
        }
        setup();
}
