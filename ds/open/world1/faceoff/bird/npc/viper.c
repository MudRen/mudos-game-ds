#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�D",({"viper",}));
 set("long",@LONG
�@���p�p���C�D.
LONG
    );
 set("race","���~");
 set("attitude", "aggressive");
 set("level",16);
 set("limbs", ({ "�Y��", "����", "����" }) );
 set("verbs", ({ "bite", "claw" }) );
 set("chat_chance",10);
 set("chat_chance_combat",200);
 setup();
}
