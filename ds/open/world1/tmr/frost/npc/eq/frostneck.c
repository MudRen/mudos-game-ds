#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name(HBK"�H���@����"NOR ,({ "frost neck","neck" }) );
        set("long","�H�����[�D�Ҩرa���@���šC\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(8000);
//              set("rigidity",10);
//              set("material", "iori");
                set("unit","��");
                set("value",10000);
                set("armor_prop/int", 1);
                set("armor_prop/armor", 1);
                set("limit_int",20);
                set("armor_prop/show_damage",1);
        }
        setup();
}
