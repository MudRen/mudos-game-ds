#include <ansi.h>
inherit NPC;
void create()
{
        set_name("��j�X" , ({ "gomon ho","ho","gomon","go","mon" }) );
        set("title", HIB "��" NOR);
         set("race","�H��");
         set("gender","�k��");
        set("age",42);
        set("level", 25);
        set_skill("blade",50); 
        set_skill("unarmed",50);        set_skill("parry",50);
        set_skill("dodge",50);
        set("long",
            "���O�Z�D���̪��`��, �g�`��o�ӷ|�|�U�a�n��C\n");
        setup();
        carry_object(__DIR__"obj/blade2")->wield();
} 

