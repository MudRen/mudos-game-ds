#include <armor.h>
#include <ansi.h>
inherit SHIELD;
void create()
{
        set_name(HIW"�p�߬޵P"NOR, ({ "cats shield", "shield" ,"�p�߬޵P"  }) );
        set("long",
                "�o�O�Q���ܶ±M�Ϊ��@��C\n");
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("armor_prop/armor",  30);
                set("armor_prop/shield",  30);
                set("armor_prop/hit",  100);
                set("armor_prop/dodge",  100);  
                set("limit_dex",4);
                set("value", 1800);
        }
        setup();
}


