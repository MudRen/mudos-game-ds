#include <ansi.h>
inherit NPC;

void create()
{
  set_name("�]�a���u��",({"guard"}));
  set("long",@LONG 
�@�ӭ]�a�����u��
LONG);
  set("attitude", "peaceful");
  set("age",42);
  set("evil",-10);
  set("gender","�k��");
  set("level",21);
  set_skill("dodge", 20);
  set("chat_chance",10);
  set("chat_msg", ({"�]�a���u�çּ֪���ۤ�.\n",}));
  setup();
  carry_object(__DIR__"eq/steel_stick")->wield();
  carry_object(__DIR__"eq/cloth")->wear();
}
