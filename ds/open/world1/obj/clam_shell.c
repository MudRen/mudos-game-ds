#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("���F��", ({ "clam shell", "shell" }) );
	set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�U�W��q, �N�O���F����.");
                }
        setup();
}
