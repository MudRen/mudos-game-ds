#include <ansi.h>
inherit NPC;
void create()
{
 set_name("海政司守衛",({"guard",}));
 set("long",@LONG
一個威風凜凜, 一副高傲樣子的守衛, 正吆喝著管理鎮上的
秩序.
LONG
    );
 set("attitude", "peaceful");
 set("age",32);
 set("gender","男性");
 set("level",17);
 set_skill("blade", 30);
 setup();
 carry_object(__DIR__"eq/sea_uniform")->wear();
 carry_object(__DIR__"eq/steel_blade")->wield();
}

