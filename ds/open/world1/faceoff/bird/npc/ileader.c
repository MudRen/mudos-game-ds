#include <ansi.h>
inherit NPC;
void create()
{
 set_name("山寨寨主",({"leader",}));
 set("long",@LONG
他就是這個山寨的寨主了, 只見他身強體壯, 看來武功頗有
根基.
LONG
    );
 set("attitude", "aggressive");
 set("age",40);
 set("gender","男性");
 set("level",41);
 set_skill("sword",80);
 set_skill("combat",20);
 set("chat_chance",10);
 set("chat_chance_combat",200);
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
 carry_object(__DIR__"eq/fur_waist")->wear();
 carry_object(__DIR__"eq/longsword")->wield();
 carry_object(__DIR__"obj/cflag");

}
