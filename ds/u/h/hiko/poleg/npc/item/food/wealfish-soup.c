#include <ansi.h>
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("�C����", ({ "wealfish soup","soup"}) );
        set_weight(190);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long", "�@�J���D�M�s���۪������C");
                set("unit", "�J");
                set("eat_msg","$N�ܤU�@�J�C�����C");
                set("eff_msg",HIG "�A�P��q�����ǨӤ@�ѷŷx�����y�A�C�C���X��������C" NOR );
           }
                set("value", 150);       
                set("heal_mp",30);
                set("water_remaining", 2);
set("cure",([
         "head" : 5,
         "body" : 5,
         "right_arm" : 5,
         "left_arm" : 5,
         "right_leg" : 5,
         "left_leg" : 5,
         ]));
set("no_auc",1);
setup();
}






