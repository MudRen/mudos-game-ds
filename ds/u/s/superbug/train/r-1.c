// Room: /u/s/superbug/train/r-1.c
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "�K��");
	set("long", @LONG
�A���b��x�e���K���W�A���ê��K�y���A�h�æ��h�[�S�������b�o�q
��F�A���e�ݥh�O�@���·t�A�ϩ����Ǫ��n�q�䤤�ĥX�N�A�]�k�F�@�ˡA
�]�\�A�ӦҼ{�O�_�e�i�Ϊ��W��x�C
LONG
    );
	set("item_desc", ([ /* sizeof() == 1 */
  "��x" : "���ȫȵ��ݤ������a��A�ݰ_�Ӧ��G�i�H���W��x�C",
]));
	set("world", "future");
	set("light", 1);
    set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"r-2.c",
]));
	set("no_clean_up", 0);

	setup();
}
void init()
{
        add_action("do_climb","climb");
}
int do_climb(string arg)
{
        object me;
        me=this_player();
        if (arg != "��x") return 0;
        message_vision("�u��$N��}�åΡA�¤�¸}�����W�F��x�C\n" ,me);
        me->move(__DIR__"3.c");
          tell_room(environment(me),me->query("name")+"�n���e�����W�F��x�C\n",me);
        return 1;
}
