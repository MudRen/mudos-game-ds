#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����" , ({ "fishing man","man" }) );
        set("level",10);
        set("race","�H��");
         set("gender","�k��");
        set("age",35);
        set_skill("parry", 20);
        set_skill("unarmed", 15);
        set_skill("dodge", 20);
        set("long","�L�O�b���䫫�������ȡC\n");
        setup();
        carry_object(__DIR__"wp/rod.c")->wield();
}
