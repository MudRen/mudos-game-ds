#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIC "�޸}�ѽu"NOR, ({ "ttoopq" }));
        set("long","��ttoopp�g�����C\n");
        set("weight", 20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
              set("unit", "��");
              set("value", 1750);
              set("heal_hp",0);
              set("heal_mp",0);
             set("heal_ap",0);
              set("food_remaining", 1);
        }
        setup();
}
