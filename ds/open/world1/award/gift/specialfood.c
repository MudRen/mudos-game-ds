#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIY"�W�Ťj�ץ]"NOR,({"super dump","dump"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�ӫܤj�ܤj�ܤj�ܤj�ܤj���]�l, �A�����D��Y�h�[�~�Y�o���C\n");
                set("unit", "��");
                set("value",1);
                set("heal_hp",20);
		set("heal_mp",20);
		set("heal_ap",20);
                set("food_remaining",50);
        }
}
