#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�I�Q�H�a",({"rich",}));
 set("long",@LONG
�@�ӦV�h�A�̰Q�Ū��ťD.
LONG
    );
 set("attitude", "peaceful");
 set("age",41);
 set("gender","�k��");
 set("level",15);
 set("chat_chance",10);
set("chat_msg", ({"�I�Q�H�a���D:�o�ǽ���٤�����٨�! \n",
}));
 set("chat_chance_combat",200);
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
}
