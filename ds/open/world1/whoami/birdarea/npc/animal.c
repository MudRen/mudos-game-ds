#include <ansi.h>
inherit NPC;
void create()
{
       set_name("�����W���ʪ�",({"noname animal","animal"}));
        set("level",5+random(15));
        set("race", "���~");
        set("age", 70);
        set("long", "�e�O�@�������W���ʪ��A�����e���@���������O�Ӱg�E\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����"}) );
        set("verbs", ({ "bite", "claw", "crash"}) );
        setup();
}

