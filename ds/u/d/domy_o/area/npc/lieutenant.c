#include <ansi.h>

inherit NPC;
void create()
{

        set_name( "上尉", ({ "lieutenant","上尉",}));
        set("long", "一位服從長官命令的年青上尉。\n");
        set("level",100);
        set("title","軍人");
        set("gender", "男性");
        set("race", "人類");
        set("age", 24);
        set("combat_exp",5000);         
        set("evil",20);
        set_skill("parry",50);                
        set_skill("gun",50);         
        set_skill("dodge",50);         
        set("attitude", "heroism");     
        set("creater","domy"); 
        set_leader("domy");
set("inquiry/domy", @LONG
  他正在努力做現代區域...不要去吵他...
LONG );


     set("chat_msg_combat", ({
(:command("kick "+this_player()->query("id")):),
 HIR"上尉大叫 :「你想做什麼?造反呀你!!」\n"NOR,
     }) );

        setup();
}

