#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�u�Y",({"worker"}));
 set("long",@LONG
�L�O���~�~������ײ�t�u�Y, �A�ݥL�@���g���o�����u
�@�A, �N�i�H���D�L�O�u�@�ԾĪ��u�Y, �]�]�����o�ؤu�H
�~�гy�X�ײ�t�����Ĳv.
LONG
    );
 set("attitude", "peaceful");
 set("evil",-20);
 set("age",34);
 set("gender","�k��");
 set("level",19);
 set("chat_chance",10);
set("chat_msg", ({"�u�Y�[�ܵۤu�H�@�u \n",
}));
 set("chat_chance_combat",200);
 setup();
 carry_object(__DIR__"eq/iron_hammer")->wield();
 carry_object(__DIR__"eq/worker_cloth")->wear();
}
