#include <ansi.h>
inherit NPC;
void create()
{
 set_name(HIB"���źX�D"NOR,({"blue flag leader","blue","leader"}));
 set("long",@LONG
�@�Ӥs�몺�X�D, �L�O�v���x�X���Y��
LONG
    );
 set("attitude", "aggressive");
 set("age",40);
 set("gender","�k��");
 set("level",15);
 set_skill("sword",40);
 set("chat_chance",10);
 set("chat_chance_combat",200);
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
 carry_object(__DIR__"eq/fur_waist")->wear();
 carry_object(__DIR__"eq/longsword")->wield();
 carry_object(__DIR__"obj/flag");

}
