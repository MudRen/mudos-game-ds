#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"����³��"NOR, ({ "elf cookie","cookie" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�����H���ұa����³�A���j�j���^�_�\\�ΡC\n");
                set("unit", "��");
                set("value", 5000);  
                set("food_remaining",5);  // janshow
                set("heal_hp",300);   // jangshow
                set("heal_ap",300);   // jangshow
                set("heal_mp",300);   // jangshow
        }
}

