#include <ansi.h>
inherit NPC;
void create()
{
 set_name("苗家村守衛",({"guard"}));
 set("long",@LONG
一個苗家村的守衛
LONG
    );
 set("attitude", "peaceful");
 set("age",42);
 set("evil",-10);
 set("gender","男性");
 set("level",21);
 set_skill("dodge", 20);
 set("chat_chance",10);
 set("chat_msg", ({"苗家村守衛快樂的聊著天.\n",
 }));
 setup();
 carry_object(__DIR__"eq/steel_stick")->wear();
 carry_object(__DIR__"eq/cloth")->wear();
}
