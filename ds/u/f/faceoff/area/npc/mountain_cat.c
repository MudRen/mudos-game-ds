#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�s��",({"cat",}));
 set("long",@LONG
�@�ر`�b�s�Ϩ��쪺�߬�ʪ�.
LONG
    );
 set("race","���~");
 set("attitude", "peaceful");
 set("level",14);
 set("limbs", ({ "�Y��", "����", "����" }) );
 set("verbs", ({ "bite", "claw" }) );
 set("chat_chance",10);
 set("chat_chance_combat",200);
 setup();
}
