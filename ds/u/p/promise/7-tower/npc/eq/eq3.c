#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(YEL"�D�ֹu"NOR, ({ "snake boots","boots" }) );
        set_weight(4000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�D�֩Ұ����u�l�A�ݰ_�Ӭ۷���o�C\n");
                set("unit", "��");
                set("value",3000);
                set("material","silk");
                set("armor_prop/str",2);
                set("armor_prop/con",2);
                set("armor_prop/int",-1);
                set("armor_prop/armor", 10);
                set("limit_lv",25);
                set("limit_str",30);
                set("limit_con",30);
        }
        setup();
}

