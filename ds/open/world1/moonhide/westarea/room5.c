inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�o�̬ݰ_�ӬO�@�������A�s�j�L��A���O���������ݪ���A����
�������A���@�ӥW�ѡA���O�@���������A���F�o�� ,�N�S���䥦����
���S�x�F�C
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"room6",
  "northeast" : __DIR__"room4",
]));
        set("light",1);
	set("outdoors","land");
        setup();
        replace_program(ROOM);
}
