        
        
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�ƶ���", ({ "pike-master-guard","guard" }) );
        set("title",HIG "�j�N" NOR);
        set("level", 38);
        set("race","�H��");
        set("gender","�k��");
        set("age",32);
        set("str", 80);
        set("con", 50); 
add("addition_armor",40);
add("addition_damage",70);        
set_skill("fork", 100);
        set_skill("parry", 40);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        set("long",
   "�@����ݪ��@�áA����D�Z�Z�����j�A�j�k��O�X���J�ơC\n");
        setup();
        carry_object(__DIR__"wp/pike_1.c")->wield();
        carry_object(__DIR__"eq/cloak_1.c")->wear();

}

