#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name("�԰��֥�", ({ "fur armor","armor" }) );
        set_weight(6000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�@�󻴥֥�, �ݨӤ��|�v�T����!\n");
                set("unit", "��");
                set("material","fur");
                set("armor_prop/armor", 16);
        }
        setup();
}