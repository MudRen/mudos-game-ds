#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name("�M����R�Y", ({ "god_pill"}));
        set("long",@LONG
�o�O�@���㦳���_���Ī����ġC
LONG
        );
        set_weight(50);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
		set("unit", "��");
		set("eat_msg","$N�Y�U�@���M����R�Y�C");
		set("eff_msg",HIG "�A�P��q�����ǨӤ@�ѷŷx�����y�A�C�C���X��������C" NOR );
	}
        set("value",750);
        set("cure",([
         "head" : 10,
         "body" : 10,
         "right_arm" : 10,
         "left_arm" : 10,
         "right_leg" : 10,
         "left_leg" : 10,
         ]));
        setup();
}
