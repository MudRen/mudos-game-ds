#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�ڶ��X",({ "hap ou yang","hap","ou","yang"}));
        set("title", HIC "�Cè" NOR);
         set("race","�H��");
         set("gender","�k��");
        set("age",43);
        set("level", 25);
        set_skill("sword",80);
        set_skill("parry",60);
        set_skill("dodge",70);
        set("long",
            "�L�O���N�Cè�A�R�C�p�g�A�C�k�y�ڥ簪�A�P�u�M�g�v�ֺ١i���C���M�j�C\n");
        setup();
        carry_object(__DIR__"wp/sword3.c")->wield();
} 
