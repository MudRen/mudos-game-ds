#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�u�H",({"worker"}));
 set("long",@LONG
�@�ӶԾĪ���t�u�H.
LONG
    );
 set("attitude", "peaceful");
 set("evil",-10);
 set("age",21);
 set("gender","�k��");
 set("level",6);
 set("chat_chance",10);
set("chat_msg", ({"�u�H�ԾĪ��b��W�׸�. \n",
}));
 set("chat_chance_combat",200);
 setup();
 carry_object(__DIR__"../wp/iron_hammer")->wield();
 carry_object(__DIR__"../eq/worker_cloth")->wear();
}
