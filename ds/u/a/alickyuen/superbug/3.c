// Room: /u/s/superbug/train/1.c
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "��x");
	set("long", @LONG
�o�̬O�@�����������a����x�A�e�s����x�o�u���}�}�������X�Ӯ�
�ȡA�ѩ�ʥF���סA�Y�W���O���@���@�����A�O�A�ݤ��M���A�b�������G
���X�ӯȽc�H�лx�g�۩��k���O�޲z�B�C
LONG
    );
	set("item_desc", ([ /* sizeof() == 1 */
  "�Ƚc" : "�@��o�󪺯Ƚc�A���G�õۨǤ���A�]�\\�A�i�H½½�ݡC\n",
"��x" : "�A�ݨ���x���ϩ����Ƕ¼v���L�A�A�߷Q�Q���U�h�ݬݡC\n",
]));
	set("world", "future");
	set("light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"1.c",
  "east" : __DIR__"5.c",
]));
	set("no_clean_up", 0);

	setup();
}
void init()
{
        add_action("do_jump","jump");
add_action("do_search","search");
}
int do_jump(string arg)
{
        object me;
        me=this_player();
        if (arg != "��x") return 0;
        message_vision("�u��$N�`�l�@�f��A���U�F��x�C\n" ,me);
        me->move(__DIR__"r-1.c");
          tell_room(environment(me),me->query("name")+"�^�F�@���A�n���e�����F�_�ӡC\n",me);
        return 1;
}
int do_search(string arg)
{
        object me,to;
        me = this_player();
        to = new(__DIR__"obj/key.c");
        if( !arg ) return 0;
        if( arg!="�Ƚc" ) return 0;
if( query_temp("getclip") )
{
    return 0;
}
        message_vision("$N�q�Ƚc��½�F½�A���F�@���_�͡C\n",me);
        to->move(me);
        set_temp("getclip",1);
	set("item_desc", ([ /* sizeof() == 1 */
"��x" : "�A�ݨ���x���ϩ����Ƕ¼v���L�A�A�߷Q�Q���U�h�ݬݡC\n",
]));
        return 1;
}
void reset()
{
        delete_temp("getclip");
	set("item_desc", ([ /* sizeof() == 1 */
  "�Ƚc" : "�@��o�󪺯Ƚc�A���G�õۨǤ���A�]�\\�A�i�H½½�ݡC\n",
"��x" : "�A�ݨ���x���ϩ����Ƕ¼v���L�A�A�߷Q�Q���U�h�ݬݡC\n",
]));
}

