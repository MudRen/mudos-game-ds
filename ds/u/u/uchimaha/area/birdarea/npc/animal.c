#include <ansi.h>
inherit NPC;
void create()
{
       set_name("�����W���ʪ�",({"noname animal","animal"}));
        set("level",15);
        set("race", "���~");
        set("age", 70);
        set("long", "�o�O�D�`�j���ΡA�e�̳��w�Y���Y�C\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����"}) );
        set("verbs", ({ "bite", "claw"}) );
        setup();
}
