#include <ansi.h>
inherit NPC;
void create()
{
       set_name("���N",({"little eagle","eagle"}));
        set("level",4);
        set("race", "���~");
        set("age", 4);
        set("long", "�o�O�@�����ݶ����^�Ӫ��p�N�C\n");
        set("limbs", ({ "�Y��", "����", "�}", "����" }) );
        set("verbs", ({ "bite", "poke" }) );
        setup();
}
