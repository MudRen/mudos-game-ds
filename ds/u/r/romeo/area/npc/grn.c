#include <ansi.h>
inherit NPC;
void create()
{
        set_name(GRN "��"NOR"���", ({ "grn" }) );
        set("level",30);
           set("combat_exp",4000);
         set("exp",1500);
set("long","�o�O�����窺���c���ǡA�����R������A�ݰ_�ӤQ�������A�]�O�������C\n");
;
        set("age",50);
        set("evil",70);
     set("title",WHT"���N"NOR);
        set("gender","�k��");
        set("attitude","killer");
             set_skill("unarmed",70);
        set_skill("dodge",60);
                  set_skill("parry",80);
        setup();
        carry_object("/u/k/king/area/npc/eq/devil-boots")->wear();
}
