#include <ansi.h>
#include <weapon.h>  
inherit SWORD;
void create()
{
        set_name(WHT"�K�C"NOR, ({ "iron sword" , "sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("unit", "��");
                set("long", "�@����Kű�����C�C\n");
                set("value", 3000);
        }
        init_sword(50);
        setup();
}

