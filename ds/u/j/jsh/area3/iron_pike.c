#include <ansi.h>
#include <weapon.h>  
inherit FORK; 
void create()
{
        set_name(WHT"�K�j"NOR, ({ "iron pike" , "pike" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("unit", "��");
                set("long", "�@����Kű�����j�C\n");
                set("value", 3000);
        }
        init_fork(50);
        setup();
}

