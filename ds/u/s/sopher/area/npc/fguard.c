#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIY"HANS警備隊員"NOR , ({ "guard" }) );
        set("level", 20);
        set_skill("parry", 60);
        set_skill("gun", 50);
        set_skill("dodge", 60);
        set("long","銳利的眼神，不愧是位好警衛。\n");
        set("chat_chance", 5 );
        set("chat_msg",({HIG"警備隊員說道：...安分點好不好..吵死了\n"NOR,
           (:command("shit"):),
           (:command("random_move"):),
           (:command("reload clip"):),
        }) );
       setup();
carry_object("/u/s/sopher/area/npc/npcwp/gun.c")->wield();
        carry_object("/u/s/sopher/area/npc/npcwp/clip.c");
}      

