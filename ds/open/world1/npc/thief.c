#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�p��",({"thief",}));
 set("long",@LONG
��, �o�O�C�ӫ����|�����Ʋ��~....
LONG
    );
 set("attitude", "peaceful");
 set("age",15);
 set("evil",10);
 set("gender","�k��");
 set("level",5);
 set_skill("dagger", 10);
 setup();
 carry_object(__DIR__"../eq/black_suit")->wear();
 carry_object(__DIR__"../wp/dagger")->wield();
}

