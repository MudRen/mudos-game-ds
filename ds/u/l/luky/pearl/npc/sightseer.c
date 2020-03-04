//sightseer.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("觀光客",({"sightseer"}));
set("level",28);
set("age",32);
set("long","一個外地來的觀光客, 正在到處買紀念品準備帶回家做紀念。\n");
set("gender", "女性");
set("combat_exp",20000+random(3000));
set("coin",500+random(200));
set("chat_chance",35);
set("chat_msg",({
  (:command,"east":),
  (:command,"get all":),
  (:command,"west":),
}) );
set_temp("apply/armor",100+random(50));
set_temp("apply/damage",random(20));
set_temp("apply/dodge",50+random(30));
setup();
set("chat_chance_combat", 25);
set("chat_msg_combat", ({
(: this_object(), "random_move" :),
HIR"\n觀光客大叫: 「搶劫啊∼﹗救命啊﹗」\n"NOR,
HIW"\n觀光客想逃可是被攔住了...跑不掉\n"NOR,
     }) );
//carry_object("/u/p/pudon/obj3/ring")->wear();
}
void init()
{
add_action("no_follow","follow");
}

int no_follow(string arg)
{
if(arg=="sightseer")
 {
 message_vision("\n[1;37觀光客對$N笑著說: [1;37m你也是來觀光的嗎?[m\n",this_player());
 message_vision("\n[1;33m觀光客說:[1;32m 那就和我一起逛逛吧。*^_^*[m\n",this_player());
 return 0;
 }
return 0;
}