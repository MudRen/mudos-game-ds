#include <ansi.h>
inherit NPC;
void create()
{
    set_name("招待員",({ "miss","招待員" }));
        set("long","一個百貨公司的小姐。\n");
	set("level", 10);
	set("age",20);
	set("chat_chance", 8);
        set("gender","女性");
    set_skill("unarmed",10);
	set_skill("dodge",25);
	set_skill("combat",5);
	setup();
        add_money("dollar",150);
}

void init()
{
	call_out("delay",2,this_player());
}
void delay(object me)
{
    tell_object(me,this_object()->name()+"對你說：歡迎光臨!!請盡情參觀!!\n");
	return;
}

void a(object tob)
{
	delete_temp("uselo");
	return;
}
