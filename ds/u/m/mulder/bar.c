#include <ansi.h>
inherit NPC;
inherit SELLMAN;

void create()
{
	set_name(MAG"酒保"NOR, ({"bartender","bar"}) );       
	set("long", "一個酒保,你可看出他一定知道好多關於Naboo的消息。\n");
	set("race", "人類");
	set("title","調酒師");
	set("age", 40);
	set("level", 5);
 //               set("talk_reply","你能幫我一點小忙(help)嗎？\n");
                set("inquiry/here","聽你的口音你好像不是這裡的人，你還是快些離開免得你走入森林。\n");
	set("inquiry/森林","森林．．．．你還是別進入．．你會打直入打橫出回來。\n");
	set("sell_list",([
		__DIR__"obj/whisky" : 8,
		__DIR__"obj/punch" : 10,
		
        ]) );
	setup();
}
void init()
{
        call_out("incheck",3,this_player());
}
void incheck(object me)
{
        if(me->query("age") != "18")
        
 {	
	message_vision("深田恭子對$N說道：" HIW "你好!你好....^_^。\n" NOR,me);
        command("wink" + me->query("id"));
	
 }
	 
	else
 {
	ob 
	move->obj
 }
 }


sdasdasdsadasdasdadadasdad
