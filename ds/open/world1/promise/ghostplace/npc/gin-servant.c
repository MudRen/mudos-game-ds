#include <ansi.h>
inherit NPC;
void create()
{
        set_name(CYN "�� ��" NOR ,({"gin servant","servant"}) );
        set("long",@LONG
�|�H�����@�A�հ��|�դ����R�G�հ�����U�C
LONG
);
        set("age",100);
        set("race","�H��");
        set("title",HIR"�|�H��"NOR);
        set("level",35);
        set("attitude", "peaceful");
        set("gender", "�k��" );
        set("chat_chance_combat",10);
        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set_skill("sword",100);
setup();
     carry_object(__DIR__"wp/whip")->wield();
       
}


