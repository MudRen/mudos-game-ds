#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�A��" , ({ "farmer" }) );
        set("level",10);
        set("race","�H��");
         set("gender","�k��");
        set_skill("parry", 20);
        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set("long",
                 "�L�O�@��b�и̨��ԯѯЪ��A�ҡC\n");
        setup();
        carry_object(__DIR__"wp/hoe.c")->wield();
}
