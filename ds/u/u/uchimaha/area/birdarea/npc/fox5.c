#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�ƪ��W",({"crazy fox", "fox"}));
        set("level",24);
        set("race", "���~");
        set("age", 16);
        set("long", "�o�O�@�������R�����𪺺ƪ��W�C\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("attitude", "aggressive");
        setup();
}
