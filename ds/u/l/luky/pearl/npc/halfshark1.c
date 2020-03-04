#include <ansi.h>
inherit NPC;

void create()
{
//=========================基本設定==========================
        set_name( "半人鯊", ({ "halfshark",}));
        set("level",45);
        set("title","[1;32m海妖[m");
        set("race", "野獸");
        set("age", 42);
        set("evil",45);
        set("war",1);
        set_skill("spear",250);
        set_skill("rapid",140);
        set("coin", random(300));
        set("long", @LONG
一隻人面鯊身的半人魚, 一口銳利的牙齒看起來十分凶殘。
LONG
        );

//========================態度類別=================================
   set("attitude", "aggressive");    //英雄主義的 NPC。

//=============================自動動作=================================
set("chat_chance", 50 );  //動作機率
set("chat_msg", ({       //動作內容
(:command("go east"):),
(:command("go west"):),
(:command("go north"):),
(:command("go south"):),
(:command("go down"):),
(:command("go up"):),
}) );


set("chat_chance_combat", 20);
set("chat_msg_combat", ({
(:command("rapid"):),
(:command("go east"):),
(:command("go west"):),
(:command("go north"):),
(:command("rapid"):),
(:command("go south"):),
(:command("go out"):),
(:command("go enter"):),
(:command("rapid"):),
(:command("go down"):),
(:command("go out"):),
(:command("go up"):),
}) );
set("limbs", ({ "頭部", "身體", "前腳", "後腳","腹部"})); //受攻部位
set("verbs", ({ "bite","claw"})); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
 setup();
//==========================裝備道具=============================
//      carry_object(__DIR__"item/bag");
      carry_object(__DIR__"wp/blackspear")->wield();
//      carry_object(__DIR__"eq/blackjacket")->wear();
}

void init()
{
 object npc, me;
 me=this_player();
 if(!me) return;
 if(this_object()->is_fighting()) return;
 this_object()->remove_all_killer();
 if(me==this_object()) return;
 if(me)
  if(!userp(me))
 { 
 if(npc=present("ovelia",environment(this_object()))) kill_ob(npc);
 if(npc=present("sightseer",environment(this_object()))) kill_ob(npc);
 if(npc=present("lamuza",environment(this_object()))) kill_ob(npc);
 if(npc=present("tifa",environment(this_object()))) kill_ob(npc);
 if(npc=present("asan",environment(this_object()))) kill_ob(npc);
 if(npc=present("guard",environment(this_object()))) kill_ob(npc);
 if(npc=present("oceaner",environment(this_object()))) kill_ob(npc);
 if(npc=present("buddy",environment(this_object()))) kill_ob(npc);
 if(npc=present("boy",environment(this_object()))) kill_ob(npc);
 if(npc=present("yuan",environment(this_object()))) kill_ob(npc);
 if(npc=present("guest",environment(this_object()))) kill_ob(npc);
 if(npc=present("tiger",environment(this_object()))) kill_ob(npc);
 if(npc=present("king",environment(this_object()))) kill_ob(npc);
 if(npc=present("squire",environment(this_object()))) kill_ob(npc);
 if(npc=present("leader",environment(this_object()))) kill_ob(npc);
 } else kill_ob(me);
}
