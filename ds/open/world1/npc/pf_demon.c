#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�ޭ��]", ({ "pigface demon","demon" }) );
        set("race","human");
        set("level",35);
        set("age",90);
        set("evil",6);
        set("long",@LONG
�����c�䪺�Ǫ��A����Y��ޤ@�Ҥ@�ˡA�]�O�ݩ�C�����]
�A�O�j�L��A�R�n�k��C
LONG
);
        set_skill("sword",90);
        setup(); 
        carry_object(__DIR__"../eq/bs_boots")->wear();
        carry_object(__DIR__"../wp/ghost_sword")->wield();
}



