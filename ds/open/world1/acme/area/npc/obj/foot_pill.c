#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name("�M���򰩤�", ({ "foot_pill"}));
        set("long",@LONG
�o�O�@���u���b�M���ľQ�~�R�o�쪺���A�������o�X�@�Ѽ���C
LONG
        );
        set_weight(5);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
	        set("unit", "��");
	        set("eat_msg","$N�Y�U�@���M���򰩤��C");
	        set("eff_msg",HIG "�A�P��L�W�Q���������A�L�W���˺C�C�����F�C" NOR );
	}
	set("value",150);
	set("cure",([
		"right_leg" : 10,
		"left_leg" : 10,
	]));
        setup();
}
