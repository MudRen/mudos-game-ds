#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�L�c�a",({"lin fen lon","lin"}));
 set("long",@LONG
�L�N�O�T�~�e��L��W�����ǩ_�H��, �]�N�O�a��L����
�V�c�a���������, ���L�L���~������H, ��ť�O�H���_, 
��b�L�k�N�L�M�L�c�a�Q�b�@�_...
LONG
    );
 set("attitude", "peaceful");
 set("evil",-100);
 set("age",62);
 set("nickname",HIG"�L�����"NOR);
 set("gender","�k��");
 set("level",4);
 set("chat_chance",10);
set("chat_msg", ({"�L�c�a���N�N���ݵۧA... \n",
}));
 set("chat_chance_combat",200);
 setup();
 carry_object(__DIR__"../eq/cloth")->wear();
}
