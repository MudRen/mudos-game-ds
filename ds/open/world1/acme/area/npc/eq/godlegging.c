#include <armor.h>
#include <ansi.h>
inherit LEGGING;
void create()
{
        set_name(CYN"���Z�@�L"NOR ,({ "god legging","legging" }) );
        set("long","���Z�дx���H�Ҭ������@�L�C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(12000);
//              set("rigidity",10);
//              set("material", "skin");
                set("unit","��");
                set("value",2000);
                set("volume",1);
                set("armor_prop/armor", 5);
        }
        setup();
}
