#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name(CYN"���Z�@��"NOR ,({ "god wrists","wrists" }) );
        set("long","���Z�дx���H�Ҭ������@��C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(8000);
//              set("rigidity",10);
//              set("material", "iori");
                set("unit","��");
                set("volume",1);
                set("value",6000);
                set("armor_prop/armor", 3);
        }
        setup();
}
