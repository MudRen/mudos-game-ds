#include <ansi.h>
inherit NPC;
void create()
{
     set_name(HIY"��"HIR"��"HIW"�R"NOR , ({ "sfuna" }) );
        set("race", "�H��");
        set("gender","�k��");
        set("age", 18);
        set("long","���n���P�������A���R���y�J�A���T�O�H�ް_�I��
�A���T�Q�˥L�@�U(kiss)�C\n");
        set("con", 10);
        set("str", 10);
        set("dex", 10);
        set("level",10);
        set_skill("sword", 10);
        set_skill("parry", 50); 
        set_skill("unarmed", 10);
        set_skill("dodge", 50);
        set("chat_chance", 5 );
        set("chat_msg",({"���ܮR���D�G�аݨӨ�ڪ���馳����ƶܡH!\n",
           (:command("smile"):),
        }) );
       setup();
}
void init()
{
add_action("do_kiss","kiss");
}

int do_kiss(string arg)
{
 if(arg=="sfuna")
 {
 message_vision("���ܮR��$N�`�۪����F���C\n",this_player());
 return 1;
 }
return 0;
}     
