#include <ansi.h>
inherit NPC;
void create()
{
 set_name("���D",({"viper",}));
 set("long",@LONG
�@���ܤj���D, ���ӬO�o�ӳD�ު��D�H�a!.
LONG
    );
 set("race","���~");
 set("attitude", "aggressive");
 set("level",20);
 set("limbs", ({ "�Y��", "����", "����" }) );
 set("verbs", ({ "bite", "claw" }) );
 set("chat_chance",10);
 set("chat_chance_combat",200);
 setup();
}
