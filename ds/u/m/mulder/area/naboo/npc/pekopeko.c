#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIB"������"NOR, ({"peko peko","peko"}) );
        set("race", "���~");
        set("age",20);
        set("level",16);
        set("attitude","peaceful");
        set("dex",30);
      set("str",20);
      set_temp("fly",1);		        
        set("long",HIB"�������O�@�����Υ��j�M�Q���ӱ��������C\n"NOR);
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}

 