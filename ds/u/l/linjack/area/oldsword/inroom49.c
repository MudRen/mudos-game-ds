#include <room.h>
inherit ROOM;
void create()
{
 set("short","�G�ӥ𮧫Ǩ��D");
 set("long",@LONG
�o�̬O�𮧫ǤG��, �o�ӼӼh�j�h���O������U����
���ͽéάO����L���̤l. �a�O�W���G���@�ǳQ�������L��
����. �n�_���䪺�ж������ǰ�f�Z���n��, ���O���H�b�m
�\.
LONG
    );
 set("exits",([ "north":__DIR__"inroom50",
                 "east":__DIR__"inroom52",
                "south":__DIR__"inroom51",
                 "down":__DIR__"inroom46",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
