#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "���ީx�L" , ({ "garrison" }) );
        set("level", 32);
        set("race","�H��");
        set("gender","�k��");
        set("age",35);
        set("int", 20);
        set("str", 50);
        set("con", 45);
        set_skill("sword", 70);
        set_skill("parry", 40);
        set_skill("unarmed", 60);
        set_skill("dodge", 45);
        set("long",
   "�t�d�u�äj���쪺���ީx�L,�L��¾��N�O�O�@�j����,�����H�a��j����C\n");
            (: random_move :),
 
       setup();

        carry_object(__DIR__"wp/longsword")->wield();
}


