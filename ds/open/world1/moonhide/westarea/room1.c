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
  "southwest" : __DIR__"room2",
  "southeast" : __DIR__"room15", 
    "south"  : __DIR__"way1",
  "north"  : __DIR__"startroom",]));
	set("outdoors","land");
        setup();
        replace_program(ROOM);
}

