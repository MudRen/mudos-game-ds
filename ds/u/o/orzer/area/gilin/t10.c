inherit ROOM;
void create()
{
        set("short","���F�˪L�谼");
        set("long",@LONG
�A����F���˪L����n��e�i�A�o�̶V���e�N��[�Pı���w�A�P��
���L��n�����w�A�ӥB�]�z�S�X�ǳ\�L�N���H��A���䪺����]�V�Ϳ@
�p�A�ݨӦ��G�ä��O����N���C
LONG
        );
        set("exits", ([
  "southwest" : __DIR__"t7",
  "north" : __DIR__"t11",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}












