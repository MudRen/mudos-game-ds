#include <ansi.h>
inherit NPC;
void create()
{
 set_name("小偷",({"thief",}));
 set("long",@LONG
唉, 這是每個城鎮都會有的副產品....
LONG
    );
 set("attitude", "peaceful");
 set("age",15);
 set("evil",10);
 set("gender","男性");
 set("level",5);
 set_skill("dagger", 10);
 setup();
 carry_object(__DIR__"eq/black_suit")->wear();
 carry_object(__DIR__"eq/dagger")->wield();
}

