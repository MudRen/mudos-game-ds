#include <ansi.h>
inherit NPC;
void create()
{
  set_name("���C", ({ "du-qing general", "du", "qing" ,"general" }) );
  set("long","���C�O�֫ӭx������F�N�x�A�t�d�F�������䨾�u�@�C\n");
  set("title", "�֫ӭx");
  set("level", 30);
  set("age", 30);
  set("no_kill",1);

   set("chat_chance", 3);
  set("chat_msg", ({
        (: command("say �]�פj�x�����{�����q�n�a�A�v�T���Զժ����ѰڡC") :),
        (: command("say �o�]�פj�x�@�餣���A�Y�s���N�@�餣�w���C") :),
        (: command("sigh�C") :),
        }));
  setup();
  carry_object(__DIR__"wp/blade")->wield();
}


