#include <ansi.h>
inherit NPC;
void create()
{
 set_name("外國商人",({"salesman"}));
 set("long",@LONG
一個外國的商人.
LONG
    );
 set("attitude", "peaceful");
 set("age",30);
 set("race","人類");
 set("gender","男性");
 set("level",5);
 setup();
 carry_object(__DIR__"../eq/cloth")->wear();
 add_money("silver",10);
}