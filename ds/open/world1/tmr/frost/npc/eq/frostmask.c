#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name(HBK"�H���K��"NOR ,({ "frost mask","mask" }) );
        set("long","�H�����[�D�Ҭ���������έ���C\n");
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
