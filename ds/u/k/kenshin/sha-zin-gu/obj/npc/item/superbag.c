#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"�U��U"NOR, ({"multirole bag","bag" }) );
        set("long", @long
�����q�񩹱`���U�l�h�ܦh�C 
long);
          set_weight(2000);
        set_max_capacity(52);
        set_max_encumbrance(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�f");
                set("volume",2);
                set("value",1000);
        }
        setup(); 
}

