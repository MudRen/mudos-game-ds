inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�o�̬ݰ_�ӬO�@�������A�s�j�L��A���O���������ݪ���A����
�������A���@�ӥW�ѡA���O�@���������A���F�o�ӡA�N�S���䥦����
���S�x�F�C
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"room1",
  "southeast" : __DIR__"room14",
]));
        set("light",1);
        	set("outdoors","land");

        setup();
        replace_program(ROOM);
}

