inherit ROOM;
void create()
{
        set("short", "�׼w��");
        set("long", @LONG
�o�̬O�׼w�����u���J�f�A��ӭ��b���f�����P�l�O�L����H��
�F����`���H�ӥ��Z�L�̪��ͬ��@���~�����A���L��ӶƨR���]���_
�X�F�@�ӳǥX���H�u�����E�v�]�ӧl�ޤF�\�h�~�Ӫ��ȫȡA���F�䨫�O
������������C
LONG
        );
        set("exits", ([
  "west" : __DIR__"villagein",
  "east" : __DIR__"village1.c",
]));
        set("no_clean_up", 0);
	set("outdoors","land");
        setup();
        replace_program(ROOM);
}
