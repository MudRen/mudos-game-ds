#include <ansi.h>
inherit NPC;
void create()
{
 set_name("����^",({"yang si chin","yang"}));
 set("long",@LONG
�����]���t��, �u���o�ֽ����յS�ө�, �������n�B, 
���M�W�F�~��, �����R���@����!
.........
�G�M���H�O���i�H�Ψ��y��F��!

LONG
    );
 set("attitude","peaceful"); 
 set("title","�x���ҤH"); 
 set("age",40);
 set("gender","�k��");
 set("level",20);
 set_skill("sky-dagger",30);
 set_skill("dagger",40);
 set("chat_chance",10);
 set("chat_chance_combat",200);
 set("chat_msg_combat",({(:command,"exert sky-dagger":),
 }));
 setup();
 carry_object(__DIR__"eq/owl_cloth")->wear();
 carry_object(__DIR__"eq/dagger")->wield();
}

