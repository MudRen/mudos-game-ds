#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(CYN"���Z�Y�y"NOR ,({ "god kerchief","kerchief" }) );
        set("long","���Z�дx���H�Ҭ������������Y�y�C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(12000);
//              set("rigidity",10);
//              set("material", "iori");
                set("unit","��");
                set("value",4000);
                set("volume",2);
                set("armor_prop/armor", 10);
                set("armor_prop/int", 1);
                set("armor_prop/hit", 3);
        }
        setup();
}
