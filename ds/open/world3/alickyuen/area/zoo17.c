// Room: /open/world3/alickyuen/area/zoo17.c
//updated by alickyuen 26/12
#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", HIC"ST�CSecret�ICyberZoo "NOR);
	set("long", @LONG
�Q����@�ӳo���c�a���ʪ���ᳺ�M�O�@���}�ª��p�ΡC�ݰ_�Ө���
���ʪ��骺�ؿv���A���G�O�H�����E�E�E�E�E�E�A���Gť��̭����ǷL��
���n���C�A���T�`�Ȱ_�ӡA�s���J��������O�H
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"zoo12",
  "enter" : __DIR__"zoo18",
]));
create_door("enter","�j�K��","out",DOOR_CLOSED);
	set("world", "future");
	set("no_clean_up", 0);
set("outdoors","land");
	setup();
	replace_program(ROOM);
}
