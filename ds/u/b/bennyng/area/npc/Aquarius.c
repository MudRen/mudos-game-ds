#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"�d��"NOR,({"aquarius"}));
        set("long",
                "    �A���e�o�Ө����_�~�y�����t�窺�H�N�O�Q�G�c���ߤ@�ϥέ��\n"
                "�����t���h!�L�K�O�B�e�����v�A�@�۴N���A����Ӧ�\n"
        );
        set("level",50);
        set("str",  65+random(10));
        set("combat_exp",50000);
        set("age",29);
        set("chat_chance",1);
        set("chat_msg",({
  (: command("say �n���˧ڡA����������s�סI�I") :),
}));
        set("chat_chance_combat",100);
        set("chat_msg_combat",({
                                (:command("exert bagi_fist"):),
  HIW"�d�����G�A�䦺�F�A�S������s�פ���ѨM��\n"NOR,
}));
        set("class","fighter");
        set("class1","�x�H");
        set("title",HIY"�_�~�y�����t���h"NOR);
        set_skill("unarmed",90);
        set_skill("dodge", 100);
        set_skill("parry", 80);
        set_skill("bagi_fist", 70);
        set_skill("combat",100);
        map_skill("unarmed","bagi_fist");
        setup();
        carry_object(__DIR__"eq/aquarius")->wear();
}
