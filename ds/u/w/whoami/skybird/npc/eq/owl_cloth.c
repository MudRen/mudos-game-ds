#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("���ΪZ��", ({ "owl cloth","cloth" }) );
        set_weight(3000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�@�󦳱��θ˹����Z�v��.\n");
                set("unit", "��");
                set("material","skin");
                set("armor_prop/armor", 6);
        }
        setup();
}
