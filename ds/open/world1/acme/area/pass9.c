// Room: /u/a/acme/area/pass9.c

#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "�s��");
	set("long", @LONG
�A�����b�@���������s���W�A���W�E�F�۪O����A���Hı�o�p�i���a
�A���@��ı�o�O�b���s�A�B�ŦӤW�A�i�樣�ѫ��������A�V�n��h���Ӥp
�p�����F�s�C�C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southdown" : __DIR__"pass10",
  "northup" : __DIR__"sdoor",
]));
	set("no_clean_up", 0);
      set("outdoors","land");

	setup();
        create_door("northup","�n����","southdown",DOOR_OPENED,"nokey");
}
