#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�p��", ({ "little ghost","ghost", "__GUARD__" }) );
        set("level",20);
           set("combat_exp",2000);
set("exp",1000);
        set("long","�L�O�@�����Y�������p���A�������������ȷȪ���ʡC\n");
        set("age",12);
        set("evil",30);
set("title",CYN"���X���S"NOR);
        set("gender","�k��");
        set("attitude","killer");
            set_skill("unarmed",40);
        set_skill("dodge",40);
           set_skill("parry",40);
        setup();
}
