// Room: /u/s/suez/grave/path_4.c

inherit ROOM;

void create()
{
	set("short", "�y�s�p�D");
	set("long", @LONG
�@���۪O�p�D�Ѧ��d��ӤW�A�b����@��j���\�F�ө^���A���֧�
���y�᧤�b���̽ͤѡA�o���p�|���O�������F���y�Ӷ}���A��Ӥ~�Q�@��
�������H���M�s���۾Q���p�D�A�H�K�n�s�C���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"path_5",
  "eastup" : __DIR__"path_3",
]));
        set("outdoors", "land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
