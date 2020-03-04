#include <ansi.h>
inherit NPC;
void create()
{
 set_name("俠客",({"wind ranger","ranger"}));
 set("long",@LONG
一個來到十萬大山除盜的疾風門俠客.
LONG
    );
 set("attitude", "peaceful");
 set("title",HIY"疾風門"NOR);
 set("age",30);
 set("gender","男性");
 set("level",20);
 set_skill("sorgi_sword",20);
 set_skill("sword",20);
 set("chat_chance_combat",200);
 set("chat_msg_combat",({(:command,"exert sorgi_sword":),
 }));
 setup();
 carry_object(__DIR__"eq/longsword")->wield();
 carry_object(__DIR__"eq/black_suit")->wear();
}
