#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�u�H",({"worker"}));
 set("long",@LONG
�@�ӥ|�B�V�����u�H, ���L�ݰ_�өǩǪ�...?
LONG
    );
 set("attitude", "peaceful");
 set("age",26);
 set("evil",-10);
 set("gender","�k��");
 set("level",9);
 set_skill("hammer", 20);
 set("chat_chance",10);
 set("chat_msg", ({"�u�H�ԧ֪��|�B�V��....\n",
		   "�u�H�ܸ޲����������@��...\n",
 }));
 setup();
 carry_object(__DIR__"eq/sea_uniform")->wear();
 carry_object(__DIR__"eq/iron_hammer")->wield();
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

