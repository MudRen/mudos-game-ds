#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HBK"�H�����u"NOR ,({ "frost boots","boots" }) );
        set("long","�H�����[�D�Ҭ��������u�C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(10000);
                set("unit","��");
                set("value",3000);
                set("volume",2);
                set("armor_prop/armor", 8);
                set_temp("apply/dodge",3);
                set("limit_dex",15);
        }
        setup();
}
