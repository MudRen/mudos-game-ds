#include <ansi.h>
inherit NPC;
void normal_ai();

void create()
{
  set_name("八岐大蛇．蛇身",({"Yamata-no-orochi's body","body"}) );
  set("long",@LONG
八頭八尾，巨大身軀有如八座山峰與八個山谷一般的恐怖大蛇身上長
杉、檜，身長跨八座山頂、山谷，腹部滴著赤血。你現在所看到的部
份是八岐大蛇的蛇身。
LONG
);
  set("race", "野獸");    
  set("unit","隻");
  set("age",2000);
  set("attitude", "peaceful");
  set("level",70);
  set("limbs", ({ "背鱗","腹鱗"}) ); 
  set("verbs", ({ "crash"}) );     
  set("chat_chance", 50);
  set("chat_msg",({
     (: normal_ai() :),
     }) );        
  setup();
}