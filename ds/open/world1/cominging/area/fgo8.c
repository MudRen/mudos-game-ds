#include <ansi.h>
inherit ROOM;
void printmessage(int time,object room);
void create()
{
        set("short", "�˪L�X�f��B");
        set("long", @LONG
�o�̴N�n��F�X�f�F�A�A�Y���W�����]�������ܤ֤F�A�]�S����
�������ΡA�������s�n�F�A�ծڤl���G�M�b�F���֡A�]����w�R�F�A�_
��N�O�˪L���X�f�F�A�F��h�O�^��˪L�����~��}�C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"fgo9.c",
  "east" : __DIR__"fgo7.c",
]));
        set("objects",([
  __DIR__"npc/obj/wtree.c" : random(4),
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
}

void printmessage(int time,object room)
{
  object me;
  me = this_player();
  if(time) tell_room("/open/world1/cominging/area/fgo8",HIY"�a���W��M���F�@���_�X��!\n"NOR);
  else tell_room("/open/world1/cominging/area/fgo8",HIC"�a���W���_��M�����F!\n"NOR);
  return;
}
