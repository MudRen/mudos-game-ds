#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("���Q���x�L", ({ "mark" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�U�W��q, �N�O���Q���x�L��!");
                }
        setup();
}
