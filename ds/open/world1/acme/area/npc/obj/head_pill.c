#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name("�M�߿�����", ({ "head_pill"}));
        set("long",@LONG
�o�O�@���u���b�M���ľQ�~�R�o�쪺���A�����e�T�����C
LONG
        );
        set_weight(50);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
	        set("unit", "��");
	        set("eat_msg","$N�Y�U�@���M�߿������C");
	        set("eff_msg",HIG "�A�P������W�U�@�}�M�D�A�믫�n�ɮ��ĳ\\�h�C\n" NOR );
        }
        set("value",150);
        set("cure",([
         "head" : 10,
         ]));
        setup();
}
