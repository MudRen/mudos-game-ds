// quest mob
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("���]¾��", ({"keeper"}) );
	set("long", "�L�O�o�����]��¾��,�i�H�V�L�߰����ӥh�����ж�(booked)�C\n");
	set("race", "�H��");
	set("age", 49);
	set("level", 5);
	setup();
}
void init()
{
        add_action("do_booked","booked");
}
int do_booked(string arg) 
{
        object me;
        me = this_player();
if(me->query_temp("bookroom") )     
return notify_fail("�A�w�q�F�СC\n");
else {
          switch(random(10))
        {
 /*    case 0:
                message_vision("$N�q���O�����СA���䪺�����C\n",me);
command("whisper "+me->query("id")+" �K�X�O���C");
me->set_temp("bookroom",1);
break;
         case 1:
                message_vision("$N�q���O�����СA�F�䪺�����C\n",me);
command("whisper "+me->query("id")+" �K�X�O���C");
me->set_temp("bookroom",1);
break;
*/         
         default:
message_vision("$N�q���O�����СA�_�䪺�����C\n",me);
command("whisper "+me->query("id")+" �ο�J(push)�K�X���A�K�X�O����C");
me->set_temp("bookroom",1);
break;       
}
}
        return 1;
}