inherit ITEM;
inherit F_PILL;
void create()
{
        set_name("�M���F�ʤ�", ({ "hand_pill"}));
        set("long",@LONG
�o�O�@���u���b�M���ľQ�~�R�o�쪺���A�A��F�@��A�������A�O�H�@���C
LONG
        );
        set_weight(50);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
	        set("unit", "��");
	        set("eat_msg","$N�Y�U�@���M���F�ʤ��C");
	        set("eff_msg","�A�P�측�����p�U���p�ʡA���h����A���O��W���˫o��_�F���֡C");
	}
        set("value",150);
        set("cure",([
         "right_arm" : 10,
         "left_arm" : 10,
         ]));
        setup();
}
