//oceaner.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("碧雷爾鎮守衛",({"pearl guard","guard"}));
set("level",32);
set("age",30);
set("long","他是本鎮的大門守衛, 一副很無聊的樣子。\n");
set("gender", "男性");
set_skill("tenken",20);
set("amount",1);
map_skill("unarmed","tenken");
set("chat_chance",5);
set("chat_msg",({
  (:command,"yawn":),
}) );
set("coin",300+random(80));
set_temp("apply/armor",100+random(50));
set_temp("apply/damage",random(20));
set_temp("apply/dodge",50+random(30));
        setup();
set_skill("unarmed",160);
set("chat_chance_combat", 25);
set("chat_msg_combat", ({
(: this_object(), "random_move" :),
HIR"\n守衛大哭: 「 饒了我吧!! 我早就不想當警衛了.. 」\n"NOR,
HIW"\n守衛想逃可是被攔住了...跑不掉\n"NOR,
     }) );
carry_object(__DIR__"eq/scalescloth")->wear();
carry_object(__DIR__"wp/club")->wield();
}
void init()
{
add_action("no_follow","follow");
}

int no_follow(string arg)
{
if(arg=="guard")
 {
 message_vision("\n[1;37m守衛突然對$N[1;37m大叫: 你跟著我想幹麻!!?。[m\n",this_player());
 message_vision("\n[1;33m守衛用力推了$N[1;33m一把, 避開了$N的跟蹤。[m\n",this_player());
 return 1;
 }
return 0;
}