#include <ansi2.h>

inherit NPC;

void create()
{
        set_name(HIW"�{���p�j"NOR,({"awardmiss"}));
        set("long",@LONG
�o�O�ﳷ�H���ʪ��{���H���C���������e�M���L�L���j�����O�H���T
�b�F�@�U�C���L�٬O�O�ѤF�V�o���(receive gift)��I
LONG
	);
        set("level",1);
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 20);
        set("evil",-20);
        set("attitude", "peaceful");
        set("no_fight",1);
        set("chat_chance", 50);
        set("chat_msg", ({
        }));
        setup();
}
void init()
{
        add_action("do_receive","receive");
}
int do_receive(string str)
{
	object me,obj;
	me=this_player();
	obj=find_object(__DIR__"record_board");
	
	if(!me) return 0;
	if(str!="gift") return notify_fail("�A�Q�⤰��H\n");
	obj->receive_gift(me);
	return 1;
}