#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(HIY"��z"HIW"���M"NOR, ({ "tiger blade" , "blade" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "��");
                set("long", "xxxxxxxxxxx�C\n");
                set("value", 2000);
        }
        init_blade(70);
        setup();
}

