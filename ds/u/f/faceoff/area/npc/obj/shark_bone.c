#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�T��", ({ "shark bone", "bone" }) );
	set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�q");
                set("long", "�U�W��q, �N�O�T�������Y.");
                }
        setup();
}
