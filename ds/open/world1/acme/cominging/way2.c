inherit ROOM;

void create()
{
	set("short", "���D");
	set("long", @LONG
�@�����������D�A�a�W�Ѥ@����������֡A�صۤ@��誺���A��
�Ǫ�Ʀܳs�A���S���ݹL�A�q�D�i�H���_�A�n�A�F�A��A���G�O�ӤQ�r
�f�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"way4",
  "north" : __DIR__"way3",
  "south" : __DIR__"way1",
]));
        set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
