#include <ansi.h>
inherit NPC;
void create()
{
  set_name("�����u��", ({ "gate guard","guard" }) );
  set("long","�u�ýY�s�����f���H�A���`�t�d�ˬd�X�J�������Ӷ��C\n");
  set("title",HIR"�֫ӭx"NOR);
  set("level",20);
  set("age",40);

   set("chat_chance", 3);
  set("chat_msg", ({
        (: command("say �w����{�Y�s���A���ťi�H�����ѤU�Ĥ@�Ϋӡu�֫ӫa��v�C") :),
        (: command("bow") :),
        }));
  set("chat_chance_combat", 14);
  set("chat_msg_combat", ({
        HIW"�u�û��G�ϤF�ϤF�A���ѤƤ餧�U�����s�����[\n"NOR,
        "�u�û��G�S�̡̭A��L���F\n"NOR
        }));
  set_skill("blade", 60);
  set_skill("parry", 70);
  set_skill("unarmed", 76);
  set_skill("dodge", 65);
  setup();
  add_money("coin",600);
  carry_object(__DIR__"wp/blade")->wield();
}


