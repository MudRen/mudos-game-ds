inherit ROOM;
void create()
{
        set("short", "������");
        set("long",@LONG
�A�q�������C�C�����F�L�ӡA�b�o�̧A�q���j���O�F�j�󪺤U��A
�ҥH�W��w�R�o���i�z��A���O�A�Ӫ������C
LONG
        );
        set("exits", ([
  "west" : __DIR__"well.c",
]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}