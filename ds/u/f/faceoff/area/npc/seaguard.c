#include <ansi.h>
inherit NPC;
void create()
{
 set_name("���F�q�u��",({"guard",}));
 set("long",@LONG
�@�ӫ­�����, �@�ư��Ƽˤl���u��, ���[�ܵۺ޲z��W��
����.
LONG
    );
 set("attitude", "peaceful");
 set("age",32);
 set("gender","�k��");
 set("level",17);
 set_skill("blade", 30);
 setup();
 carry_object(__DIR__"eq/sea_uniform")->wear();
 carry_object(__DIR__"eq/steel_blade")->wield();
}

