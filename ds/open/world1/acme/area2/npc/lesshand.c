#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�L�Y��", ({ "lesshead ghost","ghost","lesshead", "__GUARD__" }) );
        set("level",22);
          set("combat_exp",2200);
set("exp",2000);
        set("long","�L�O�@���S���Y�����A�ݨ���ά۷��ӡC\n");
        set("age",30);
        set("evil",26);
set("title",CYN"���X���S"NOR);
        set("gender","�L��");
        set("attitude","killer");
           set_skill("unarmed",44);
           set_skill("dodge",44);
           set_skill("parry",44);
        setup();
}
