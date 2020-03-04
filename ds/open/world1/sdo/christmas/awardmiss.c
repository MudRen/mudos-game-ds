#include <ansi2.h>

inherit NPC;

void create()
{
        set_name(HIW"頒獎小姐"NOR,({"awardmiss"}));
        set("long",@LONG
她是堆雪人活動的頒獎人員。甜美的笑容和水汪汪的大眼睛令人不禁
呆了一下。不過還是別忘了向她領獎(receive gift)喔！
LONG
	);
        set("level",1);
        set("gender", "女性");
        set("race", "人類");
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
	if(str!="gift") return notify_fail("你想領什麼？\n");
	obj->receive_gift(me);
	return 1;
}