// Room: /u/a/acme/area/ndoor.c

#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "�_�Z��");
     set("light",1);
	set("long", @LONG
�o�̬O�Ѥs�ѫ����_�����A�����W���T�Ӷ¦�j�r�A�W���g�ۡi�_�Z
���j�A���_���i���}�ѫ��ӳq���Ѧ��A�n��i�ܤѫ��������C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"pathway2.c",
  "north" : __DIR__"pass",
]));
	set("objects", ([ /* sizeof() == 1 */
   __DIR__"npc/garrison" : 3,
]));
	set("no_clean_up", 0);

	setup();
        create_door("north","�_����","south",DOOR_OPENED,"nokey");
}
int valid_leave(object me, string dir)
{
       if( dir=="north" && me->query("sky_city_war") )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}
