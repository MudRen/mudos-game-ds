#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIR"�N�s"HIW"�ֹu"NOR, ({ "cho-long boots","boots" }) );
        set_weight(2500);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�W�j�s�֩һs���u�l\n");
                set("unit", "��");
                set("value",3000);
                set("material","fur");
                set("armor_prop/dex",3);
                set("armor_prop/armor", 14);
        }
        setup();
}

