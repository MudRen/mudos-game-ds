#include <room.h>
inherit ROOM;
void create()
{
 set("short","�𮧫Ǩ��D");
 set("long",@LONG
�o��M�ﭱ���~���ȩХ��n�ۤ�, �o�̪��ж����O���V����
�������ݦb�𮧪��a��. ���D�Q�����b, �u�O�S�����ȩШ��D��
����R�Ӥw. ���@�ǭ�𮧧����H�b�o�䨫�Ө��h, ���]���A��
�Ө�ӷP�즳�I���w.
LONG
    );
 set("exits",([ "north":__DIR__"inroom41",
                 "east":__DIR__"inroom7",
                "south":__DIR__"inroom42",
                 "west":__DIR__"inroom43",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
