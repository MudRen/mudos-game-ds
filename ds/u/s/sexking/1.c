#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIC"純潔小麥草"NOR , ({ "small sexking","small","sexking" }) );
        set("long",@long
一個很可愛的小男生，手上拿著一疊文件到處發給人。
long
);
        set("age", 5);
        set("no_fight",1);
        set("level", 1);
        set("title","活潑可愛");
        set("gender", "男性");
        set("race", "人類");
        set("chat_chance",10);
        set("chat_msg", ({       
name()+"說道: 快來夢幻七域網站投稿可拿特殊貢獻值ㄛ。\n",
(: command("smile") :),
(: command("ccc") :),
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
                        command("say 這位帥哥辣妹！快去看看夢幻七域的網站吧！");
                        break;
                case 1:
        bill=new(__DIR__"bills");
        bill->move(ob);
message_vision("純潔小麥草給了$N一張廣告傳單。\n",ob);
                        command("snicker");
                        break;
        }
}


