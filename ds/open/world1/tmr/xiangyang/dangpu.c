// Room: /d/xiangyang/dangpu.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
        set("short", "��Q");
        set("long", @LONG
�o�O�a����D�W����Q�A�T�}���������A�@���g�ۡy����
��Q�z�|�Ӫ��r���°СA�����C�ذ������Ȥ쪺�d�x�Q�i�o��
�i�ӤH�A�A�@�i�h�N���@������M�d�����Pı�A�d�x�᪺����
�����Y�]���諸�u�U���Եۺ�L�A�d�x�W�豾�ۤ@�����P�l
(plate) �C�ڵ�{�̻��K����Q�������٤�����a�A�åB�q��
�ݳf���ӳB�A���F���H���򳣦��A�ҥH�ͷN�ܤ����C
LONG );
        set("item_desc", ([
                "plate" : "
�A�����@�A��������C\n",
        ]));
        set("no_fight", 1);
        set("no_beg", 1);
        set("exits", ([
                "south" : __DIR__"westjie1",
        ]));
        set("objects", ([
//         __DIR__"npc/qiuhang" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

