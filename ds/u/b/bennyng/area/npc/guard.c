#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"�t��u��"NOR, ({ "Saint guard","guard" }) );
        set("long","�@��t��u�áA�V�O�a�u�@�t�쪺�w���C\n");
        set("level",25);
        set("age",25);
        set("combat_exp", 29000);
        set("chat_chance", 4);
        set("chat_msg", ({
  "�t��u�û��G���Ӹt�켻���A���������C\n",
}));
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
  HIW"�t��u�û��G�䦺�A����Ѥl�·СA��������\n"NOR,
  "�t��u�û��G�S�̡̭A���L�Ӳ��X\n"NOR
}));
        set_skill("parry", 70);
        set_skill("unarmed", 80);
        set_skill("dodge", 50);
        setup();
        carry_object(__DIR__"eq/boots")->wear();
        carry_object(__DIR__"eq/armor")->wear();
}
