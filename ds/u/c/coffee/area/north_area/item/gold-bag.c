#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"�����U"NOR, ({ "gold bag","bag" }) );
        set("long", 
"�@�f���Ϊ��⥬�Ʃһs�����U�l�A���G�Z�öQ���C\n"
);
          set_weight(3000);
        set_max_capacity(50);
        set_max_encumbrance(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�f");
                set("volume",5);
                set("value",5000);
        }
        setup(); 
}
