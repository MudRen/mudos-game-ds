
#include <ansi.h>
inherit ITEM;
inherit F_WATER;
void create()
{
    set_name(RED"�d�����"NOR, ({ "cappuccino","coffee" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("long","�ο@�Y�@�ءB�����Φ׮ۯ��ջs�����~�C\n");
              set("unit", "�M");
          set("value", 12000);    
          set("heal_mp",3000);
          set("water_remaining", 1);
        }
        setup();
}

