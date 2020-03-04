#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"ST.FIRE�IDPY�a�U�G��"NOR);
	set("long", @LONG
�U��Ӧa�U�G�ӡA�A�o�{�o�̪����֤�W���٭n�˧n�o�h�A�H�̳��b
�ƨg�a���R�A���ǤH�b�ܰs�C�b�A�����⭱�O�@�Ӥj�s�d�M�@�ʸt�Ͼ�A
�s�O����H���b�c���a���H�Ȱe�s�C
LONG
	);
 set("exits",([ 
"up":__DIR__"dpy1.c",
"down":__DIR__"dpy3.c",
]));
	set("world", "future");
set("light", 1);
	set("no_clean_up", 0);
set("item_desc",(["�s�d":"�o�O�@�ө�s���s�d,�ݰ_�Ӧ��@�Ǥ����q.....\n",
"�t�Ͼ�" : "�@�ʫܰ��j����A�W�Y���@�ɬP�P���b�{�ۡA�u�O�Q�⥦�ˤU�ӥΡC\n", 
])); 
	setup();
}
void init()
{
	add_action("typepush","push");
add_action("do_pick","pick");
}
int do_pick(string arg)
{
        object me,to;
        me = this_player();
        to = new(__DIR__"obj/star.c");
        if( !arg ) return 0;
        if( arg!="�P�P" ) return 0;
if( query_temp("getstar") )
{
    return 0;
}
        message_vision("$N�����a�q�t�Ͼ�W���U�F�P�P�C\n",me);
        to->move(me);
        set_temp("getstar",1);
set("item_desc",(["�s�d":"�o�O�@�ө�s���s�d,�ݰ_�Ӧ��@�Ǥ����q.....\n",
])); 
        call_out("delay",180,this_object());
        return 1;
}
int typepush(string arg)
{
 	object me;
	me=this_player();
	if (arg != "�s�d") 
                   return 0;
	else {
                   message_vision("�u��$N��@���A�K�s�H�a�d���t�@�өж��̡C\n\n" ,me);
                   me->move(__DIR__"drm1");
                   tell_room(environment(me),me->query("name")+"��M�X�{�b�A���e�Cn",me);
	   return 1;
                 }
}

void delay(object room)
{
      delete_temp("getstar");
set("item_desc",(["�s�d":"�o�O�@�ө�s���s�d,�ݰ_�Ӧ��@�Ǥ����q.....\n",
"�t�Ͼ�" : "�@�ʫܰ��j����A�W�Y���@�ɬP�P���b�{�ۡA�u�O�Q�⥦�ˤU�ӥΡC\n", 
])); 
        return;
}
