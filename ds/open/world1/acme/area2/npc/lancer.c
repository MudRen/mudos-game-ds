#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "���j�a��", ({ "ghost lancer","ghost","lancer","__GUARD__" }) );
        set("level",28);
           set("combat_exp",2800);
set("exp",1500);
        set("long","�L�O�խߦa�������Ϻj����A�M�����Ȧb�h���ԧФ��A�X���F�L�Ʀn��C\n");
        set("age",50);
        set("evil",40);
        set("gender","�k��");
        set("title",CYN"���X���S"NOR);
        set("attitude","killer");
           set_skill("fork",56);
           set_skill("dodge",56);
           set_skill("parry",56);
        setup();
        carry_object(__DIR__"wp/lance.c")->wield();
           carry_object(__DIR__"eq/hands.c")->wear();
}
