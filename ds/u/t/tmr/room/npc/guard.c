#include <ansi.h>

inherit NPC;

void create()
{
        set_name( HIC "守門護衛" NOR , ({ "guard" }) );
        set("con", 19);
        set("age",30);
        set("str", 20);
        set_skill("sword", 60);
        set_skill("parry", 60);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set("long",
                "一個守護房門的護衛，看起來三十幾歲\n"
                "渾身肌肉，看來武藝也有相當程度，讓人\n"
                "看了不敢在此撒野..。\n");
        set("chat_chance", 5);
        set("chat_msg", ({
                "守門護衛自言自語地說道：" HIG "保護奇爺是我的畢生的責任，我一定會做好它的!!\n" NOR,
                "守門護衛對著天大聲說道：" HIG "爹、娘，孩兒定會不負所託，保護奇爺生生世世!!\n" NOR,
        }));
        setup();
        carry_object(__DIR__"obj/sword.c")->wield();
}
void init()
{
        add_action("do_guard", "go");
	call_out("incheck",3,this_player());
	
}
void incheck(object me)
{
	if(me->query("id") != "tmr")
	{
                say("守門護衛說道：" HIG "走開走開，不要在這逗留.....\n" NOR);
		command("angry");
 	}else
    	  {
	        say("守門護衛說道：" HIG "奇大人在上，小的祝你千歲千歲千千歲.....\n" NOR );
	        command("bow");
	  }
}

int do_guard(string arg)
{

       if( (arg!= "south") || !this_player()->visible(this_object()) ) return 0;
        write( name() + "將你攔了下來。\n");
        command("hehe");
        say("守門護衛說道：" HIB "小子可別亂闖啊!!\n" NOR);
        return 1;
}
