#include <weapon.h> 
#include <ansi.h>
inherit AXE;
void create()
{
        set_name(HIW"�������"NOR, ({ "tooth big-axe" , "axe" }) );
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",10);
                set("unit", "��");
                set("long", "�@������������, ���ˤO��@�몺���Y�j�C\n");
                set("value", 2000);
        }
        init_axe(35);
        setup();
}

