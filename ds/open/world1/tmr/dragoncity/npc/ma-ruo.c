#include <ansi.h>
inherit NPC;
void create()
{
  set_name("���Y", ({ "ma-ruo general", "ruo" ,"general" }) );
  set("long","���Y�O�֫ӭx�����Z���N�x�A�t�d�_�������䨾�u�@�C\n");
  set("title", "�֫ӭx");
  set("level", 30);
  set("age", 30);
  set("no_kill",1);

   set("chat_chance", 3);
  set("chat_msg", ({
        (: command("say �H����O�K��ڪ��@��e�W�x�ȡA�X�Ӥ�e�b�_���~����A�����ӰʡC") :),
        (: command("say �o�H����@�餣���A�Y�s���N�@�餣�w���C") :),
        (: command("sigh�C") :),
        }));
  setup();
  carry_object(__DIR__"wp/blade")->wield();
}

