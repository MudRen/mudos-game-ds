#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�ѹ�", ({"rat"}) );
        set("long", "�@�������ë����p�ʪ�, �᭱�٩�ۤ@�����������ڡC\n");
        set("unit","��");
        set("race", "���~");
        set("limbs", ({ "�Y��", "����", "����", "��}","�e�}"})); //���𳡦�
        set("verbs", ({ "bite","claw","crash"})); //�������A��hoof��crash�rbite��claw��poke
        set("age", 1);
        set("level",1);
        set("dex",1);
        set("str",1);
        set("con",1);
        set("hp", 1000000000);
        setup();

}

