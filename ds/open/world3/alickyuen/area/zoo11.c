//update by alickyuen 30/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST�CPark�ICyberZoo"NOR);
	set("long", @LONG
�o�̬O�ʪ��餺���@�Ӥp����A�C�Ȳ֤F�i�b�o�̥𮧤@�|��A�A�]
�i�ݨ�ܦh�H�b���ۡA�|�B�����ҫܦn�C���A�o�{���ᦳ�ǩM�H�@�밪��
���O�A�A���T�h�ø̭����õۤ���C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"zoo5",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
}
void init()
{
	add_action("do_pass","pass");
}
int do_pass(string arg)
{
 	object me;
	me=this_player();
	if (arg != "���O") 
                   return 0;
	else {
                   message_vision("$N�b���O�襤��F��A��M���F�@�����C\n\n" ,me);
                   me->move(__DIR__"zoo12");
                   tell_room(environment(me),me->query("name")+"���F�L�ӡC\n",me);
	   return 1;
                 }
}
