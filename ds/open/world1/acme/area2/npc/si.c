#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�׳~�h", ({ "do tu si","do","tu","si", "__GUARD__" }) );
        set("level",36);
        set("combat_exp",3600);
set("exp",2500);
        set("long","�L�O���ۤj�M���Ѫ̡A���۷��G�p�A�o���o�_�I�����Z���C\n");
        set("age",70);
        set("evil",70);
        set("title",HIR"�s�]�ûR"NOR);
        set("gender","�k��");
        set("attitude","killer");
        set("Merits/wit",2);
        set_skill("blade",72);
        set_skill("dodge",72);
        set_skill("parry",72);
        setup();
        carry_object(__DIR__"wp/blade2.c")->wield();
}
