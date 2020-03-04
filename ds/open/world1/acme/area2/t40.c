// Room: /u/a/acme/area2/t40.c

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
  "south" : __DIR__"t41",
  "southwest" : __DIR__"t39",
]));
      set("objects",([
         __DIR__"npc/sun" : 1,
      ]));
  set("item_desc", ([ /* sizeof() == 1 */
      "�j��" : "�o�O�@�����⪺�j���A�����G�W�F��C\n",
      "����j��" : "�o�O�@�����⪺�j���A�����G�W�F��C\n",
  ]) );
 
  set("hide_exits", ([
  ]));
	set("no_clean_up", 0);


	setup();
	create_door("south","����j��","north",DOOR_LOCKED,"redkey");
}
