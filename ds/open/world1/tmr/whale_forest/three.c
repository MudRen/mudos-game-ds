// File: /d/whale_forest/three.c
// Updated by tmr (Tue Feb 26 23:07:53 2002)

inherit ROOM;

void create()
{
	  set("short", "��W");
	  set("long", @LONG
�A�����b�@�I��F�W�A����ѩ�𸭪���������o���o���@�C�o�̶Z
���a������G���ءA�n�U�h�]�O���������ơC�ѩ�𸭾�K���c�K�A�ϱo
�o����۳��D�A���r�r����F�W�u���F�ǳ\�C�a�A�ݨӳo��`���ʪ����g
�L���C
LONG
	  );
	  set("exits", ([ /* 1 element(s) */
	"down" : __DIR__"map_6_7",
]));
	  set("outdoors", "forest");
set("objects",([
                __DIR__"npc/squirrel":4,
                  __DIR__"npc/obj/shortpike":1,
        ]));

	setup();
	  replace_program(ROOM);
}
