// Room: /u/a/acme/area/sdoor.c

#include <path.h>
#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "�n�Ȫ�");
     set("light",1);
	set("long", @LONG


[33m         �i�i�i    �i�i�i    �i�i�i    �i�i�i    �i�i�i    �i�i�i[0m
         [33m�i�i�i    �i�i�i    �i�i�i    �i�i�i    �i�i�i    �i�i�i[0m
         [33m�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i[0m
         [33m�i�i�i�i�i�i�i�i�i�i�i[0m  [36m��    ��  [33m�i�i�i�i�i�i�i�i�i�i�i[0m
[33m         �i[35m�Ѥs�q�X�n��ġA[33m�i�i�i�i�i�i�i�i�i�i[35m�v���Ѵ�C�L���F[33m�i[0m
         [33m�i�i�i�i�i�i�i�i�i�i�i[33m�~--------��[33m�i�i�i�i�i�i�i�i�i�i�i[0m
         [33m�i[35m�̭��E�|���A�i�F[33m�i�i[33m��   ��   ��[33m�i�i[35m�����e�}�G�p���C[33m�i[0m
         [33m�i�i�i�i�i�i�i�i�i�i�i[33m��  .��.  ��[33m�i�i�i�i�i�i�i�i�i�i�i[0m
         [33m�i�i�i�i�i�i�i�i�i�i�i[33m��   ��   ��[33m�i�i�i�i�i�i�i�i�i�i�i[0m
         [33m�i�i�i�i�i�i�i�i�i�i�i[33m��   ��   ��[33m�i�i�i�i�i�i�i�i�i�i�i[0m

         �o�N�O�Ѥs�ѫ����n�����F�A�o�̧A�i�H�ݨ�H�ӤH���A�n
     �����x�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"street.c",
  "southdown" : __DIR__"pass9",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/garrison" : 3,
]));
	set("no_clean_up", 0);

	setup();
        create_door("southdown","�n����","northup",DOOR_OPENED);
}
int valid_leave(object me, string dir)
{
       if( dir=="southdown" && me->query("sky_city_war") )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}
