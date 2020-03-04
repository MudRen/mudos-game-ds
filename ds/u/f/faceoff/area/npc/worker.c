#include <ansi.h>
inherit NPC;
void create()
{
 set_name("工人",({"worker"}));
 set("long",@LONG
一個四處敲打的工人, 不過看起來怪怪的...?
LONG
    );
 set("attitude", "peaceful");
 set("age",26);
 set("evil",-10);
 set("gender","男性");
 set("level",9);
 set_skill("hammer", 20);
 set("chat_chance",10);
 set("chat_msg", ({"工人勤快的四處敲打....\n",
		   "工人很詭異的彼此對望一眼...\n",
 }));
 setup();
 carry_object(__DIR__"eq/sea_uniform")->wear();
 carry_object(__DIR__"eq/iron_hammer")->wield();
}

void init()
{
       add_action("typepush","push");
}
     int typepush(string arg)
{
        object me;
        me=this_player();
        if(arg != "牆壁") return 0;
        message_vision("工人閃身遮在$N面前!!\n\n",me);
        message_vision("工人很勉強的笑著說: 小兄弟, 咱們要做工呢...!\n\n",me);
        return 1;
}

