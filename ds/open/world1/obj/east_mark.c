#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�F�Ʈv���x�L", ({ "mark" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�U�W��q, �N�O�F�Ʈv���x�L��!");
                }
        setup();
}
