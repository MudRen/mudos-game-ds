// Room: /u/t/tmr/area2/forest3.c

inherit ROOM;

void create()
{
	set("short", "�ծ|");
	set("long", @LONG
�o�O�@���˪L�����ծ|�A�ר�|�P�L��ѤѡA���q�J���A�ɾB���u�A
��o�|�P���t�����A��ձަ樫�A���p�©]����⤣���A�ݤ��|�g����
�H�N�A�������y���]�~��A�x�l�y�p���H���Ȥw�I�ѳۦa�F�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"forest5",
  "southwest" : __DIR__"forest2",
]));
          set("outdoors","forest");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
