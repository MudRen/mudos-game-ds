// File: /d/barbarian_island/thief_room.c
// Updated by tmr (Sat May 11 16:22:35 2002)

inherit ROOM;

void create()
{
	  set("short", "������");
	  set("long", @LONG
�A���B�b�ѳ���G��򦨪��@�������̡A�ѩ�|�g�����ᰪ�B�K
���A�u�n�Y�ۨ��l�ۦb�o�̡A�Q�����L���H�]�����o�{�o�̳o��@������
���è��B�C
LONG
	  );
	  set("exits", ([ /* 1 element(s) */
	"south" : __DIR__"map_8_9",
]));
        set("objects",([
                __DIR__"npc/thief":1,
        ]));
	  set("outdoors", "forest");

	setup();
	  replace_program(ROOM);
}
