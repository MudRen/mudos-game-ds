#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�H��", ({ "monster man","man", "__GUARD__" }) );
           set("level",12);
           set("combat_exp",1200);
        set("gender","�L��");
       set("evil",35);
set("long" ,"�L�O�@��b�H�b�����Ǫ��A���زu��A�Q�����G�C\n");
        set("age",25);
           set_skill("unarmed",24);
           set_skill("parry",24);
           set_skill("dodge",24);
            set("attitude","killer");
        setup();
}
