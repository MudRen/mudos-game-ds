#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�~��ӤH",({"salesman"}));
 set("long",@LONG
�@�ӥ~�ꪺ�ӤH.
LONG
    );
 set("attitude", "peaceful");
 set("age",30);
 set("race","�H��");
 set("gender","�k��");
 set("level",5);
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
 add_money("silver",10);
}