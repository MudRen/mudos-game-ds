// Room: /open/world1/tmr/bagi/rift.c
#include <ansi.h>
#include <path.h>
#include <room.h>

inherit ROOM;

inherit DOOR;
void create()
{
        set("short", "�s���e");
        set("long", @LONG
�b�A���e�����j�s���A�䶡���@�s�_�A���i�e�@�H�����ӹL�A�ɦ��L
���q���ӨӡA��L�s�_�ɦ]�ۿi�ӱa�����n�C���W�M�O����B����A�B�d
�����ơA�Q�k���W�s���A���L�i��C
LONG
        );
        set("item_desc", ([ /* sizeof() == 2 */
  "east" : (: look_door,     "east" :),
  "�s�_" : "�}��s�����������_�A���G���H�u���d�X�ӡC
",
]));
        set("world", "past");
        set("outdoors", "land");
        set("exits", ([ /* sizeof() == 2 */
//"north" : "/open/world1/baal/ming_club/cablecar",
  "east" : "/open/world1/tmr/area/s_house",
]));
        set("no_clean_up", 0);

        setup();
      create_door("east", "���", "west", DOOR_CLOSED);
}
void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg!="�s�_" ) return 0;
        message_vision("$N�@�Y���A�N���s�������s�_���F�i�h�C \n",me);
        me->move(__DIR__"rift1");
          tell_room(environment(me),me->query("name")+"���F�L�ӡC\n",me );
        return 1;
}
