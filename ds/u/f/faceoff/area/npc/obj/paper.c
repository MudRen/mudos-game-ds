#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("簽出條", ({ "paper" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
	set("value",1);
                set("unit", "張");
                set("long", "這是海政司發給合格船隻的簽出條.");
                }
        setup();
}
