#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIY "��"NOR"��ѩ�", ({ "hiy" }) );
        set("level",37);
           set("combat_exp",5000);
         set("exp",2000);
set("long","�o�O������窺���c���ǡA�����R������A�ݰ_�ӤQ�������A�]�O�������C\n");
;
        set("age",60);
        set("evil",80);
     set("title",WHT"���N"NOR);
        set("gender","�k��");
        set("attitude","killer");
             set_skill("unarmed",80);
        set_skill("dodge",90);
                  set_skill("parry",90);
        setup();
        carry_object("/u/k/king/area/npc/eq/devil-shield")->wear();
}
