#include <ansi.h>
inherit NPC;
void create()
{
 set_name("包達廷",({"bou da tin","bou","tin"}));
 set("long","他是無砂陣中最最長舌的人, 有關村裡的事據說他無所不知..。\n");
 set("age",56);
 set("gender","男性");
 set("level",30);
 set("title",HIG"包打聽"NOR);
 set_skill("combat",100);
 set("chat_chance",20);
 set("chat_msg", ({"包達廷說道: 有沒有啥事不知道ㄚ...我可以跟你說(talk)ㄛ!!..\n",
                   (:command("sigh"):),
 }));
	set("chat_chance_combat",200);

 set("chat_msg_combat",({                         
                         (:command,"hmm":),
 }));

	set("inquiry/綽號","就是王霸最最討厭的綽號啊....就是王八狗官嘛!\n"NOR);

	set("inquiry/漁商","最近漁商的漁獲都很差, 所以也接受賣魚, 看來是一個賺錢的好機會呢!.\n"NOR);

	set("inquiry/寶貝","聽說是林鎮長的傳家之寶? 到底是啥也沒人見過, 不過一定在鎮長公宅裡吧?.\n");

	set("inquiry/高人","就是鹽俠嘛! 他行刺王霸失敗後好像就躲到人流複雜的地方了, 像市集啊......\n"NOR);
 setup();
}

int talk_action(object me)        
{
 object book;
 if(!book=me->query_temp("notebook")) return 0;
 command("smile "+me->query("id") );
 if(random(2))
 {
        command("say 最近無砂事真多呢!");
        command("say 聽說有一些無賴們在打林鎮長的『寶貝』的主意呢。");
        command("say 那混帳王霸, 昨日才帶了十幾個官兵不知幹啥去了?");
        command("say 最近的漁穫都不怎麼好, 聽說『漁商』們都要去喝西北風了....");
      command("say 聽說有一個『高人』去行刺王霸失敗, 如今不知道躲在哪呢!");
        command("sigh");
        command("say 說到王霸, 他城府還真深呢! 不過你只要叫他的『綽號』他一定會氣死 ");
 }
 
 return 1;
}