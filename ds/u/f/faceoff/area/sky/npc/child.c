#include <ansi.h>
inherit NPC;
void create()
{
 set_name("����",({"child"}));
 set("long",@LONG
�@�Ӧb���l����B���A���p��....
LONG
    );
 set("attitude", "peaceful");
 set("age",4);
 set("evil",-10);
 set("gender","�k��");
set("level",3);
 set_skill("dodge", 20);
 set("chat_chance",10);
 set("chat_msg", ({"�����Ԧ�A���⻡: �n���n�@�_��~?\n",
                   "�����ּּ֧֪��]�Ӷ]�h....\n",
 }));
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
}
