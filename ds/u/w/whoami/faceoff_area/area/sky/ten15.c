#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", CYN"�@���ȴ�"NOR);
        set("long", @LONG
�A�@�i�ӡA���W�Pı��@�Ѿ���o�S��U����^�A�ȴ�
�����M�S������ȤH�A���O�̤��ȫo�����o�G�A�ӷs�A��
�Ů��_�q��Ū��ȵ����j�i�A�u���A���k����@�T��r�e
�A��k��_�A�����O����ҩҬ��A�ӥ�����h���@�y�ӱ�
���W.
LONG
        );
        set("exits", ([  "north" : __DIR__"ten12.c",
                   "up":__DIR__"ten16.c",
]));
      set("objects", ([__DIR__"npc/ten_waiter" : 1,
    ]));
   set("item_desc",([
        "��r�e": "�o�T��r�e�Ѫk��U, �Q�ӥ������H�Ҭ�, �W���g�� "+WHT+" �m���Ӫ��K��, �@���s�Ҫ١n"+NOR+"\n"
    ]));
           set("room_type","hotel");       //���]
        set("no_fight", 1);
        set("light",1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        setup();
}
