#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�M��", ({ "blade chi","chi","blade", "__GUARD__" }) );
        set("level",14);
       set("gender","�k��");
set("exp",500);
          set("combat_exp",1400);
              set("attitude","killer");
        set("long" ,"�L�O�խߦa�������M�ϡA���L�ͩʤ��n�Z�A�G�M�k�y�ڥ礣�j�C\n");
        set("age",40);
        set("evil",40);
           set_skill("blade",28);
                set_skill("dodge",28);
                set_skill("parry",28);
        setup();
        carry_object(__DIR__"wp/blade.c")->wield();
}
