#include <ansi.h>
inherit NPC;
void create()
{
 set_name("村童",({"child"}));
 set("long",@LONG
一個在村子中到處玩耍的小孩....
LONG
    );
 set("attitude", "peaceful");
 set("age",4);
 set("evil",-10);
 set("gender","男性");
set("level",3);
 set_skill("dodge", 20);
 set("chat_chance",10);
 set("chat_msg", ({"村童拉住你的手說: 要不要一起玩~?\n",
                   "村童快快樂樂的跑來跑去....\n",
 }));
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
}
