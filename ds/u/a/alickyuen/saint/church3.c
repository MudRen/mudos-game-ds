//updated 26/12
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIC"ST�DChurch�IGod of moon"NOR);
	set("long", "�Ө�o�̡A�S�O�@�f�s�����H�C�A�ݨ�o�̪������]���@�L��v����
�A���o�L����o�S�����X�ӡC�䦸�A�S�o�{�b�a�𪺦�m���@��÷���A�A
���G�i�H�a�L�^��W���F�C\n");
        set("item_desc", ([ /* sizeof() == 2 */
  "÷��" : "�@���ʲʪ�÷�A�A�i�H�Q�Υ������C\n",
"��v����" : "�@�y�������۹�,���@�I���i��ĳ....\n",
]));
        set("objects", ([ /* sizeof() == 4 */
 __DIR__"npc/goda" : 1,
]));
set("light",1);
	setup();
}
void init()
{
        add_action("do_climb","climb");
add_action("do_search","search");
}
int do_climb(string arg)
{
        object me;
        me=this_player();
        if (arg != "÷��") 
                   return 0;
        else {
                   message_vision(HIR"$N�j�O����÷���A�C�C�a���X�o�̡C\n\n"NOR ,me);
                   me->move(__DIR__"church2");
                   tell_room(environment(me),me->query("name")+"��M�X�{�b�A���e�C\n",me);
           return 1;
                 }
}
 int do_search(string arg)
{


        object gun;
                object me;
        me=this_player();
 if( me->query_temp("killgoda") )
{
       if (arg != "��v����") return 0;
if(query_temp("getgun")) return notify_fail("��F�S��A�רs�@�L����...\n");
        message_vision("$N�b��v���������_�̥J�ӥJ�Ӫ��j�M...\n"  ,me);
 message_vision("��F�S��A$N�ש�b���_�̧��F�@��i��v����j�I�I\n" ,me);
gun=new(__DIR__"obj/wp/moongun.c");
gun->move(me);
set_temp("getgun",1);      
  call_out("delay",600,this_object());
        return 1;  
 delete_temp("getgun");   
me->delete_temp("killgoda");                           
}
}

