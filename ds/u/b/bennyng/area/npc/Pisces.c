#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"���iù�}"NOR,({"pisces"}));
        set("long",
                "    �A���e�o�Ө��������y�����t�窺�H�N�O�Q�G�c���̫�@�����\n"
                "�t���h!�L�����������i���O�|�@�L���A�A�n�p�����I\n"
        );
        set("level",50);
        set("str",  65+random(10));
        set("combat_exp",50000);
        set("age",27);
         set("chat_chance",1);
        set("chat_msg",({
  (: command("say �Q���ЬӡH���ݹL�Ѥl�a") :),
}));
        set("chat_chance_combat",100);
        set("chat_msg_combat",({
                                (:command("exert bagi_fist"):),
  HIW"���iù�}���G�䦺�A����Ѥl�·СA��������\n"NOR,
}));
        set("class","fighter");
        set("class1","�x�H");
        set("title",HIY"�����y�����t���h"NOR);
        set_skill("unarmed",90);
        set_skill("dodge", 100);
        set_skill("parry", 80);
        set_skill("bagi_fist", 70);
        set_skill("combat",100);
        map_skill("unarmed","bagi_fist");
        setup();
        carry_object(__DIR__"eq/pisces")->wear();
}
