#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�p�Ǻ�",({ "bear" }) );
        set("level",7);
        set("race", "���~");
      set("str",3);
       set("age", 1);
        set("long", "�e�O�@���p�����Ǻ��C\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("attitude", "aggressive");
        setup();
}
