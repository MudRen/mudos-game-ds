#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�u��",({"guard"}));
 set("long",@LONG
�o�O�@�ӥ|�B���ު��Ѿ¦u��
LONG
    );
 set("attitude", "peaceful");
 set("age",26);
 set("nickname",HIC"�Ѿ�"NOR);
 set("evil",-10);
 set("gender","�k��");
set("level",27);
 set_skill("sword", 30);
 set("chat_chance",10);
 set("chat_msg", ({"�u�å|�B������....\n", }));
 setup();
 carry_object(__DIR__"eq/steel_sword")->wield();
 carry_object(__DIR__"eq/sky_cloth")->wear();
}
