#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���]��", ({ "axe-master-guard","guard" }) );
        set("title",HIG "��N" NOR);
        set("level", 40);
        set("race","�H��");
        set("gender","�k��");
        set("age",32);
        set("str", 70);
        set("con", 50);
        add("addition_armor",50);        
        add("addition_damage",50);        
        set_skill("axe", 100);
        set_skill("parry", 40);
        set_skill("unarmed", 50);
        set_skill("dodge", 40);
        set("long",
   "�@����ݪ��@�áA����D�Z�Z�����j�A��k��O�X���J�ơC\n");
        setup();
        carry_object(__DIR__"wp/axe_1.c")->wield();
        carry_object(__DIR__"eq/ring_1.c")->wear();
 
}

