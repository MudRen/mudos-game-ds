#include <ansi.h>
#include <weapon.h>  
inherit GUN; 
void create()
{
        set_name(WHT"�K�}"NOR, ({ "iron bow" , "bow" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("unit", "��");
                set("long", "�@����Kű�����}�C\n");
                set("value", 3000);
        }
        init_gun(50);
        setup();
}

