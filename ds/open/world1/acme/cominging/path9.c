inherit ROOM;

void create()
{
	set("short", "���D");
	set("long", @LONG
�b�o�̦��@�ӯS���ж��A���G�N�O�|����������§�С��A�̭���
���D���O����H�A�n���ܯ������ˤl�A�_���٦��@�ǩж��A�����D�S
�O������Ϊ��F�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
//  "east" : __DIR__"house4",
  "west" : __DIR__"path1",
  "north" : __DIR__"path8",
]));
        set("light",1);

	setup();
	replace_program(ROOM);
}
