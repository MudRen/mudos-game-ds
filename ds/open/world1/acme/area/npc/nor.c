#include <ansi.h>
inherit NPC;
void create()
{
          set_name("�|����",({ "neither fish nor fowl","fowl" }) );
           set("level",12);
             set("str",5);
             set("con",18);
      set("int",6);
        set("race", "���~");
        set("age", 6);
        set("long", "�e�O�@�����o���j�A�ṳ���A�Y���F�����A���Ӥ������|�����C\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����","����" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}
