#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name(HIY"�{�p�ۤ���"NOR, ({"thunder necklace","necklace","thunder" }) );
        set("long", "�@���Φ��p�q���_�۶���C\n");
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("armor_prop/armor",  3);
                set("armor_prop/dex", 3);
                set("value", 10000);
        }
        setup();
}
