#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIY"HANSĵ�ƶ���"NOR , ({ "guard" }) );
        set("level", 20);
        set_skill("parry", 60);
        set_skill("gun", 50);
        set_skill("dodge", 60);
        set("long","�U�Q�������A���\�O��nĵ�áC\n");
        set("chat_chance", 5 );
        set("chat_msg",({HIG"ĵ�ƶ������D�G...�w���I�n���n..�n���F\n"NOR,
           (:command("shit"):),
           (:command("random_move"):),
           (:command("reload clip"):),
        }) );
       setup();
carry_object("/u/s/sopher/area/npc/npcwp/gun.c")->wield();
        carry_object("/u/s/sopher/area/npc/npcwp/clip.c");
}      

