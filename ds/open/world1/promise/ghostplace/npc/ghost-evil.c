#include <ansi.h>
inherit NPC;
void create()
{
        set_name(RED "����" NOR ,({"ghost evil","evil"}) );
        set("long",@LONG
�|�������@�A�հ��|�դ����R�G�հ�����U�C
LONG
);
        set("age",100);
        set("race","�H��");
        set("title",HIC"�|����"NOR);
        set("level",30);
        set("attitude", "peaceful");
        set("gender", "�k��" );
        set("chat_chance_combat",10);
        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set_skill("sword",100);
setup();
     carry_object(__DIR__"wp/sword")->wield();
       
}


