#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIB "�L��"NOR"��", ({ "ghost kind","ghost","kind" }) );
        set("level",35);
           set("combat_exp",4000);
         set("exp",3000);
set("long","�o�O�@���a���L�ͧ�M���l�Ӫ��Y�Y�A���W���_���]���ֳ�C\n");
;
        set("age",50);
        set("evil",70);
     set("title",CYN"�۫�"NOR);
        set("gender","�k��");
        set("attitude","killer");
             set_skill("unarmed",90);
        set_skill("dodge",70);
                  set_skill("parry",70);
        setup();
        carry_object("/u/k/king/area/npc/eq/devil-mask")->wear();
}
