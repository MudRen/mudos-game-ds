#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�W�x��", ({ "blade-master-guard","guard" }) );
        set("title",HIG "�M�N" NOR);
        set("level", 35);
        set("race","�H��");
        set("gender","�k��");
        set("age",35);
        set("dex", 60);
        set("con", 70);
        add("addition_armor",70);        
        add("addition_damage",60);                
        set_skill("blade", 100);
        set_skill("parry", 60);
        set_skill("unarmed", 70);
        set_skill("dodge", 80);
        set("long",
   "�@����ݪ��@�áA����D�Z�Z�����j�A�M�N��O�X���J�ơC\n");
        setup();
        carry_object(__DIR__"wp/blade_1.c")->wield();
        carry_object(__DIR__"eq/shield_1.c")->wear();
}


        
        
        
 


