#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","����");
set("long",@LONG
�A�B��ܦ�, �H��w�g��ֳ\�h, ���L�٬O���ǳ\���ȫȨ�
�o�̬ݤ@��, �A�o�{�b�A���n�䦳�X�ӹ��L�X���۫�, �ݨӦ�
�Ǯɤ�S���D�H�o!
LONG
    );
 set("exits",([ "west":__DIR__"seacoun26",
		"east":__DIR__"seacoun24",
]));
 set("item_desc",([
        "�۫�":"�@�Ƥp�p���۫�, �A�i�H���i�h(enter)�ݬ�.\n"
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
}            

void init()
{
       add_action("typeenter","enter");
}
     int typeenter(string arg)
{
        object me,obj;
        me=this_player();
	obj=this_object();
        if(arg != "�۫�") return 0;
        message_vision("$N�G���i�J�F�۫�.\n",me);
	me->move(__DIR__ "seacoun28");
        return 1;
}
