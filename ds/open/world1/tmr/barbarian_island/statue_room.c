// File: /d/barbarian_island/statue_room.c
// Updated by tmr (Wed May  8 23:39:09 2002)

inherit ROOM;

void create()
{
	  set("short", "�۬}");
	  set("long", @LONG
�o�̬O�@�B����Ϊ���j�۬}�A�j�p���i�e�ǤQ�ƤH�b���A�u�ۥ۾�
�I�ۼƪK���G������A��}���ӱo�צp�ձޯ�A�i�M���@���F��C
LONG
	  );
	  set("exits", ([ /* 1 element(s) */
	"out" : __DIR__"map_4_14",
]));

        set("objects",([
                __DIR__"npc/destroy-statue":1,
        ]));
	setup();
	  replace_program(ROOM);
}
