#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name("���Υ֥�", ({ "owl armor","armor" }) );
        set_weight(6000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�@�󦳱��λ��֥�, �ݨӤ��|�v�T����!\n");
                set("unit", "��");
                set("material","skin");
                set("armor_prop/armor", 17);
        }
        setup();
}
