#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"��ù"NOR,({"capricorn"}));
        set("long",
                "    �A���e�o�Ө���s�Ϯy�����t�窺�H�N�O�Q�G�c���ﶮ��\n"
                "�R�̩��ߪ��t���h!�L����M��t�C�����i�}�ѱ��a�A�A�o�n�p��\n"
        );
        set("level",50);
        set("str",  65+random(10));
        set("combat_exp",50000);
        set("age",26);
        set("chat_chance",2);
        set("chat_msg",({
  (: command("say �ѤU�L�����t�C�D�D�A�n�ոն�??") :),
  (: command("say �t���h���S���H��ڹﶮ��R����") :),
}));
        set("chat_chance_combat",100);
        set("chat_msg_combat",({
                                (:command("exert bagi_fist"):),
  HIW"��ù���G�����ҿסA�����t�C���F�`�a�I�I�I\n"NOR,
}));
        set("class","fighter");
        set("class1","�x�H");
        set("title",HIY"�s�Ϯy�����t���h"NOR);
        set_skill("unarmed",95);
        set_skill("dodge", 100);
        set_skill("parry", 75);
        set_skill("bagi_fist", 70);
        set_skill("combat",100);
        map_skill("unarmed","bagi_fist");
        setup();
        carry_object(__DIR__"eq/capricorn")->wear();
}
