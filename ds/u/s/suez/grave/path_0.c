// Room: /u/s/suez/grave/path_0.c

inherit ROOM;

void create()
{
	set("short", "���ѱV");
	set("long", @LONG
�V�W���ѡA�G�M���p�t�a�Ѥ��A��������A�P�ᬰ�F�A�U�i�@������
�A�W�i�p���C�ѡA�U�@�غئ��p�L�����ϡA�W�Q���ߦb���w���_�s�A�W��
��V�ڡA�����G��U�V���u�A�q�q�G��d���g���A�Ѥ��j�ܦ��誾�A�u��
�ת��Ѫ��R�]�C
LONG
	);
        set("outdoors", "land");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"path_1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
