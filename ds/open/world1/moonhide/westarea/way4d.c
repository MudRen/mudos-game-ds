inherit ROOM;

void create()
{
        set("short", "���ݶ���");
        set("long", @LONG
�A���b�@�B���ݶ���W�A�}�U�򪺬O�ιΥժ�᪺�����A�A�]���M��
�H���i�௸�b���W�A�o���T�O�Ӥ��Ѥ��g�C���ݶ��詹�W�i�H�q������
�s���A���U�i�H���^��a���C
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
    "up" : __DIR__"way4.c",
    "down" : __DIR__"way4d2.c",
]));
        set("no_clean_up", 0);
        set("outdoors", "land");
        set("current_light", 1);

        setup();
        replace_program(ROOM);
}

