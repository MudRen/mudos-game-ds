
#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�]�C",({"meo chen","meo","chen"}));
 set("long",@LONG
�L�N�O�Ѿª��u�ê��F, �]�O�ѭ]�a���Ҭ��X�Ӫ�....
LONG
    );
 set("attitude", "peaceful");
 set("age",34);
 set("nickname",HIC"�Ѿ�-�u�ê�"NOR);
 set("evil",-10);
 set("gender","�k��");
set("level",35);
set("str",100);
set("con",100);
 set_skill("sword", 100);
 set("chat_chance",30);
 set("chat_msg", ({"�]�C�§A�ݤF��.....\n", 
          (: random_move :),
        }) );
 setup();
 carry_object(__DIR__"eq/silk_cloth")->wear();
 carry_object(__DIR__"eq/sky_sword")->wield();
}
