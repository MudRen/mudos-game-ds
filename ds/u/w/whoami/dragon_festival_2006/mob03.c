#include <ansi.h>
inherit NPC;
void create() 
{ 

 set_name("屈原",({"qu yuan","qo","yuan"}));
 set("age",2302);
 set("gender","男性");
 set("level",50);
 set("title",HIC"忘記帶泳褲"NOR);
 set("chat_chance",10);
 set("chat_msg", ({"屈原高聲唱道﹕心鬱鬱之憂思兮，獨永歎乎增傷。\n",
                   (:command("sing 河底風光無限好"):), 
 }));

 setup();
}
