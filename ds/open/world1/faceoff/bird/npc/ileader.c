#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�s���D",({"leader",}));
 set("long",@LONG
�L�N�O�o�Ӥs�몺��D�F, �u���L���j�駧, �ݨӪZ�\�ᦳ
�ڰ�.
LONG
    );
 set("attitude", "aggressive");
 set("age",40);
 set("gender","�k��");
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
