#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�ƪ�" , ({ "crazy dog", "dog", "__GUARD__" }) );
        set("level",4);
           set("combat_exp",400);
       set("gender","����");
        set("age",5);
        set("race","���~");
              set("attitude","killer");
       set("evil",12);
        set("long","�o�O�@���L���y�ۤf�����ƪ��C\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}
