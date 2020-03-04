// Room: /u/a/acme/area/wdoor.c

#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "��ت�");
     set("light",1);
	set("long", @LONG
�o�̴N�O���Ѥs���ѫ��F�A�o�O�ѫ������䫰���A�u�������W�g
�F�T�Ӷ¦�j�r�i��ت��j�A�۪��ݰ_�Ӭ۷����¡A�]�~�[���סA��
�ɪ������@�������p�ۤl�A���G���h�[�K�|�ɭˡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"street2",
  "southwest" : __DIR__"pass2.c",
]));
	set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/garrison" : 3,
]));
	set("no_clean_up", 0);
	setup();
create_door("southwest","�諰��","northeast",DOOR_OPENED,"nokey");
}
int valid_leave(object me, string dir)
{
       if( dir=="southwest" && me->query("sky_city_war") )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}
