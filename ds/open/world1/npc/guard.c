#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�����L��",({"vagabond",}));
 set("long",@LONG
�@�ӳB�B�i���������L��, ���L���Y���ت��ˤl���A�ݤF��
��Q��.
LONG
    );
 set("attitude", "peaceful");
 set("age",41);
 set("gender","�k��");
 set("level",20);
 set("chat_chance",10);

set("chat_msg", ({"�����L�����C�n���D:���ѧ�L���Y�� "+HIY+"�_��"+NOR+" ���N��!!. \n",
	           	  "�����L��o�{�A�b�ݥL, �c�������§A���F�@��.. \n",
}));
 set("chat_chance_combat",200);
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
 carry_object(__DIR__"eq/longsword")->wield();
}
void init()
{
       add_action("typepush","push");
}
     int typepush(string arg)
{
        object me;
        me=this_player();
        if(arg != "���") return 0;
        message_vision("�u�H�{���B�b$N���e!!\n\n",me);
        message_vision("�u�H�ܫj�j�����ۻ�: �p�S��, ���̭n���u�O...!\n\n",me);
        return 1;
}




