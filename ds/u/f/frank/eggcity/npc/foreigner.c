#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�v�H", ({ "foreigner","man" }) );
        set("long","�񲴷����Y�v���H�A�@�Ѩ�ߦb���ǹǹǯQ�ԩԪ��ܡA���L�L�̨��W��\n"
                   "�O���ǭȿ����n�F��C\n");
        set("level",10+random(10));
        set("age",20+random(3));

        set("combat_exp", 20000);
        set("chat_chance", 4);
        set("chat_msg", ({
  "�v�H���D : �ǹǫΩԩԡI\n",
  "�v�H���D : ��㽼���ڡI\n",
  "�v�H���D : �̨̰ڶ��I\n"
}));
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (:command("say �ǹǫΩԩԡI"):),
                (:command("say ��㽼���ڡI"):),
                (:command("say �̨̰ڶ��I"):),
                (:command("help!"):),
                       }) );
        
        set_skill("parry", 70);
        set_skill("unarmed", 80);
        set_skill("dodge", 65);

        setup();
        carry_object(__DIR__"obj/gem-ring")->wear();
        carry_object(__DIR__"obj/gem-kerchief.c")->wear();
}
