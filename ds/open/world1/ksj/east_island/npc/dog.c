#include <ansi.h>
inherit NPC;
void create()
{
  set_name("��Ф�", ({ "akita","dog" }));
  set("long",@long
�ݩ�j�����A�O�y�~���P�g����t�ӱo�쪺���ءA�W�Q�򬰲ʪ����u
��A�U�Q��u�ӱK�͡A��⦳����B���۳¦�B�զ�B�ժ۳¦�B��
�۳¦�B�æ���򴳡A���ڤ������򬰥զ�A����ڦV�W�����P����
����⦨���A��o�Q�����R�C
long);      
  set("race","���~");
  set("age",3);
  set("level",7);
  set("limbs", ({ "�Y��","����","����","�e�}","��}" }) );
  set("verbs", ({ "bite", "claw"}));
  set("chat_chance", 5);
  set("chat_msg",({
  "��Ф���_�Y�ӡA�§A�n�F�n���ڡC\n",
  "��Ф��C�Y��b�A�᭱�A���ɻD�D�A���}��C\n",
  (: command("dog"):),
  }));
  setup();
}
