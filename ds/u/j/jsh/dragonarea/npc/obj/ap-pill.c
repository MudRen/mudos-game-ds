#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIC"����Y"NOR, ({ "Ap-pill","ap-pill" }) );
        set_weight(40);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@���׶��U�ظɮ��ħ��@�Y�Ҧ����A�Q�����Q�C\n");
                set("unit","��");
                    set("value",500);        
                    set("heal_ap",200);           
                    set("food_remaining",1);
        }
     setup();
}

