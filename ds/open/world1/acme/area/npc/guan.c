#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�W�x�E" , ({ "jui shang guan","jui","shang","guan" }) );
        set("title", HIG "�M�g" NOR);
         set("race","�H��");
         set("gender","�k��");
        set("age",43);
        set("level", 25);
        set_skill("blade",80);
        set_skill("parry",60);
        set_skill("dodge",70);
        set("long",
            "�L�O���N�M�g�A�R�M�pè�A�M�k�y�ڥ簪�A�P�u�Cè�v�ֺ١i���C���M�j�C\n");
        setup();
        carry_object(__DIR__"wp/blade2.c")->wield();
} 
