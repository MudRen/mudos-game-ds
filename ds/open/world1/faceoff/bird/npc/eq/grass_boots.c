#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name("����i", ({ "grass boots","boots" }) );
        set_weight(2500);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�@���ѱ��Z�H�`�諸�u�l!\n");
                set("unit", "��");
                set("material","plant");
                set("armor_prop/shield",3);
                set("armor_prop/armor", 3);
        }
        setup();
}
