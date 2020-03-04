// Room: /u/a/acme/area2/t41.c

#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "�խߦa��[�a�U�|�h]");
	set("long", @LONG
�A�����b�·t�L�񪺦a�D���A�a�D���S���A�n�������������A�V
�����Y�߸̶V�`�ȡA�o�Ѷ·t����y�O�A�����C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"t42",
  "north" : __DIR__"t40",
]));
  set("item_desc", ([ /* sizeof() == 1 */
      "�j��" : "�o�O�@�����⪺�j���A�����G�W�F��C\n",
      "����j��" : "�o�O�@�����⪺�j���A�����G�W�F��C\n",
  ]) );
 
  set("hide_exits", ([
  ]));
	set("no_clean_up", 0);

	setup();
    create_door("north","����j��","south",DOOR_LOCKED,"redkey");
}
int valid_leave(object me, string dir)
{
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("�o�̤ӹL�����F�A�A�����L�h�C\n");
    return ::valid_leave(me, dir);
}

