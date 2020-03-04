//oceaner.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("海底居民",({"oceaner"}));
set("level",24);
set("age",30);
set("long","他是本鎮的居民, 正在悠閒的逛街。\n");
set("gender", "男性");
set_skill("tenken",20);
map_skill("unarmed","tenken");
set("coin",300+random(100));
set("chat_chance",15);
set("chat_msg",({
  (:command,"north":),
  (:command,"south":),
}) );
set_temp("apply/armor",100+random(50));
set_temp("apply/damage",random(20));
set_temp("apply/dodge",50+random(30));
        setup();
set_skill("unarmed",160);
set("chat_chance_combat", 25);
set("chat_msg_combat", ({
(: this_object(), "random_move" :),
HIR"\n海底居民大叫: 「可惡的外來者∼﹗吃我這一拳﹗」\n"NOR,
HIW"\n海底居民想逃可是被攔住了...跑不掉\n"NOR,
     }) );
//carry_object("/u/p/pudon/obj3/ring")->wear();
}
void init()
{
add_action("no_follow","follow");
}

int no_follow(string arg)
{
if(arg=="oceaner")
 {
 message_vision("\n[1;37m海底居民突然對$N[1;37m大叫: 你跟著我想幹麻!!?。[m\n",this_player());
 message_vision("\n[1;33m海底居民用力推了$N[1;33m一把, 避開了$N的跟蹤。[m\n",this_player());
 return 1;
 }
return 0;
}