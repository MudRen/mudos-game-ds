#include <weapon.h>
#include <ansi.h>

inherit AXE;

void create()
{
        set_name(HIY"�^������"NOR,({"hero axe","axe"}) );
        set("long","�Ȯɥγo�ӦW�r...\n");
        set_weight(16000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
        set("unit","��");
        set("volume",2);
        set("value",1000);
        }
        init_axe(30);
        setup();        
}

