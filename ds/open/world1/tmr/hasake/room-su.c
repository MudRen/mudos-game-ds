// room-su1.c 

inherit ROOM;
string look_sign(object me);

void create()
{
        set("short", "Ĭ�|�J���a");
        set("long", @LONG
�ѩ�Ĭ�|�J���d�l�Q�~�e�Q�j�s�`���A�u�ѤUĬ�|�J�M�L��lĬ����
�H�A�ҥH�θ̶äC�K�V���C��Ĭ�|�J�ä��b�N�A�]���Lı�o���L�o�˪���
��~�l�O����h���k�H�̰����Ʊ����C����@�Ǫ��j����W���ۨ��i��
�P���Ϥ��l�C
LONG
        );
        set("exits", ([
            "northeast" : __DIR__"shuijing",
        ]));


        set("objects", ([
                    __DIR__"npc/su" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
