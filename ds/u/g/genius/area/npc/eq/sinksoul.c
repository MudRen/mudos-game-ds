#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(CYN"沉魂"NOR, ({ "sink soul","soul" }) );
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("long","這是一只淡藍色的戒指，表面隱隱發出晶瑩的光輝，有一股不凡的智慧隱含其中。\n");
        set("unit", "只");
        set("value",0);
        set_weight(450);
        set("material","jade");
        set("armor_prop/armor", 5);
        set("armor_prop/int",3);
        }
        setup();
}

