#include <ansi.h>
//updated by alickyuen 
inherit NPC;
void create()
{
	set_name( "宣傳人員" , ({ "sales" }) );
	set("long",@long
一個宣傳人員，他正在派發傳單介紹新開張的蛋糕店。
long
);
	set("age", 60);
	set("level", 5);
 set("race", "人類");
  set("chat_msg", ({       
(:command("hehe"):),  
     (: random_move :),
}) );
	setup();
}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob,object bill)
{
  if( !ob || environment(ob) != environment()|| objectp(present("handbills", ob))  ) return;
        switch( random(2) ) {
                case 0:
                        command("say 這位旅人，快一些去SAINT東大街的蛋糕店吧，剛剛開張，有很多款蛋糕賣唷！");
                        break;
                case 1:
        bill=new(__DIR__"obj/handbills");
        bill->move(ob);
message_vision("宣傅人員給了$N一張傳單。\n",ob);
                        command("hehe");
                        break;
        }
}

