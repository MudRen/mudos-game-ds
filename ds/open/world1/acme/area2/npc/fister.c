#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�����L��", ({ "ghost fister","ghost","fister" , "__GUARD__"}) );
        set("level",24);
           set("combat_exp",2400);
set("exp",1000);
        set("long","�L�O�խߦa�����������A���k��w��F�X���޵Ѫ����ɡC\n");
        set("evil",40);
        set("age",45);
        set("gender","�k��");
        set("title",CYN"���X���S"NOR);
        set("attitude","killer");
            set_skill("unarmed",48);
            set_skill("dodge",48);
           set_skill("parry",48);
        setup();
        carry_object(__DIR__"wp/fist.c")->wield();
}
