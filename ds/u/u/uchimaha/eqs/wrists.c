#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name(HIC"NIKY�@��"NOR, ({ "niky wrists", "wrists" }) );
        set("long",
                "�o�O�Q���ܶ±M�Ϊ��@��C\n");
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("armor_prop/armor",  8);
                set("armor_prop/shield",  8);
                set("armor_prop/hit",  100);
                set("armor_prop/dodge",  100);  
                set("limit_dex",4);
                set("value", 1800);
        }
        setup();
}
