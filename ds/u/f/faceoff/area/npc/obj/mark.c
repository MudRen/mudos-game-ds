#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(CYN"徽記"NOR, ({ "eagle mark", "mark"}) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
	set("value",1);
                set("unit", "個");
                set("long", "一個形狀似鷹的徽記, 聽說是西方一代游擊隊的徽記");
                }
        setup();
}
