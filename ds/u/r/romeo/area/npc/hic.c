#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIC "�P��"NOR"����", ({ "hir" }) );
        set("level",37);
           set("combat_exp",5000);
         set("exp",2000);
set("long","�@�ӥR���������ǡA�S�H���D�L�q���̨ӡA�|����̥h�C\n");
;
        set("age",60);
        set("evil",80);
     set("title",WHT"�]��"NOR);
        set("gender","�k��");
        set("attitude","killer");
             set_skill("unarmed",90);
        set_skill("dodge",90);
                  set_skill("parry",90);
        setup();
        carry_object("/u/k/king/area/npc/eq/devil-helmer")->wear();
}

