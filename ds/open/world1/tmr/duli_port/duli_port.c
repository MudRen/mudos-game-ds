// File: /d/duli_port/duli_port.c
// Updated by tmr (Wed Feb 27 21:10:52 2002)

inherit ROOM;

void create()
{
	  set("short", "������-�n��B");
	  set("long", @LONG
�A�����b������f���X���X�Y�A�@����h�A�������O�H��A�@�i�@�i
�a�Q�n���W�U�@�Z��A�Ů����ۧn�x�B�j�n��ͩM����ŧ�Ӫ��@�Ѯ��v
�����D�C�@�����F���D���A�q����������c�����a�q�C
LONG
	  );
	  set("exits", ([ /* 1 element(s) */
	"east" : __DIR__"map_6_1",
]));
        set("objects",([
               "/d/batogiya_dtl/npc/ha-biao" : 1,
        ]));
           set("outdoors","land");
           set("no_fight",1);
               set("where","duli_port");

	setup();
	  replace_program(ROOM);
}
