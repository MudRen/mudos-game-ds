#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�ȤH" ,({ "traveler" }) );
        set("level",4);
        set("race","�H��");
        set("gender","�k��");
        set("age", 35);
        set("long", "�L�O�@�ӹC�M�@�ɦU�a���ȤH�C\n");
        set("evil",-10);
        setup();
        carry_object(__DIR__"wp/sword.c")->wield();
         add_money("coin",100);
} 

