#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( "�����U", ({ "gold-silk bag","bag" }) );
        set("long", 
"�@�f���Ϊ��⥬�Ʃһs�����U�l�A���G�Z�öQ���C\n"
);
        set_weight(3000);
        set_max_capacity(60);
        set_max_encumbrance(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�f");
                set("volume",5);
                set("value",5000);
        }
        setup(); 
}
