#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"�Ь�"NOR,({"gemini"}));
        set("long",
                "    �o�ӤH�N�O�����H�������Ь�\n"
                "�۶ǥL�O�����t���h�䤤�@��!!\n"
        );
        set("level",60);
        set("str",  80+random(10));
        set("combat_exp",60000);
        set("age",30);
        set("chat_chance",3);
        set("chat_msg",({
  (: command("say �Q����A��Ө�o�a") :),
  (: command("say �u�O���i��N!!") :),
  (: command("say �A�ǳƨ����a!!!") :),
}));
        set("chat_chance_combat",120);
        set("chat_msg_combat",({
                                (:command("exert bagi_fist"):),
  HIW"�Ьӻ��G�K�K�I�I�S���H�ӧ䦺�I�I\n"NOR,
  HIW"�Ьӻ��G�K�K�I�I�s�H�ӵ��A���ͧa�I�I\n"NOR,
}));
        set("class","fighter");
        set("class1","�x�H");
        set("title",HIY"�t��D�H"NOR);
        set_skill("unarmed",100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("bagi_fist", 100);
        set_skill("combat",100);
        map_skill("unarmed","bagi_fist");
        setup();
        carry_object(__DIR__"eq/gemini")->wear();
}
