#include <weapon.h> 
#include <ansi.h>
inherit SWORD; 
void create()
{
        set_name("���C", ({ "long sword" , "sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "��");
                set("long", "�@����C�A�S����S�O���a��C\n");
                set("value", 1000);
        }
        init_sword(35);
        setup();
}

