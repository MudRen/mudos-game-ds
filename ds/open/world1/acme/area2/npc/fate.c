#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "���R��", ({ "balance fate herald","balance","fate","herald", "__GUARD__" }) );
        set("level",35);
           set("combat_exp",3500);
set("exp",1500);
        set("long","�L�O�@���W���ۯ��誺�ѤH�A�����Q�����c�C\n");
        set("age",70);
        set("evil",70);
        set("title",HIR"�s�]�ûR"NOR);
        set("gender","�k��");
        set("attitude","killer");
           set_skill("whip",70);
                 set_skill("dodge",70);
                set_skill("parry",70);
        setup();
         carry_object(__DIR__"wp/beam.c")->wield();
       carry_object(__DIR__"eq/neck.c")->wear();
}
