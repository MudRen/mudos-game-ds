#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�@�éx�L" , ({ "guard" }) );
        set("level", 25);
        set("race","�H��");
        set("gender","�k��");
        set("age",30);
        set_skill("sword", 50);
        set_skill("parry", 40);
        set_skill("unarmed", 70);
        set_skill("dodge", 55);
        set("long",
   "�t�d���ޯ�������x�L,�L��¾��N�O�O�@��������w��,�����H�b����̾x�ơC\n");
            (: random_move :),
 
       setup();

        carry_object(__DIR__"wp/longsword")->wield();
}

