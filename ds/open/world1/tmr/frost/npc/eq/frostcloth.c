#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HBK"�H������"NOR ,({ "frost cloth","cloth" }) );
        set("long","�H�����[�D�H�Ҭ������]��A�C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(15000);
//              set("rigidity",10);
//              set("material", "iori");
                set("unit","��");
                set("value",6000);
                set("volume",2);
                set("armor_prop/armor", 20);
                set("armor_prop/dex", 1);
                set("limit_con",15);
        }
        setup();
}
