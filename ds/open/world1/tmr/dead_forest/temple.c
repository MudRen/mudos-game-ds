// File: /d/dead_forest/temple.c
// Updated by tmr (Fri Feb 20 22:02:43 2004)

inherit ROOM;

void create()
{
	  set("short", "�j�q");
	  set("long", @LONG
�o�O�@�y�o�󦳼ƤQ�~���[���j�q�A�ɼ٬W�l�W���w�g�G���F
�j����A�q���ѩ^���ƴL�����]���O�ǹСA�W�Y�������]�X�G���]
�~�[�ӭ鸨�U�ӤF�A�i���w�g�ܤ[�S���H�ӹL�F�C
LONG
	  );
	  set("exits", ([ /* sizeof() == 1 */
	"out" : __DIR__"map_16_19",
]));
	  set( "objects" , ([
	  	  __DIR__"npc/yang-xiao" : 1,
	  	  ]) );

	setup();
	  replace_program(ROOM);
}
