#include <room.h>
inherit ROOM;
void create()
{
 set("short","���U");
 set("long",@LONG
�A�q�L�F�@�����Y�Ө�F�o�V���󪺥��U����, �u����
�����@��j�����ѥߦa���ժ��W�l, �W�����s���, �n����
��. ��ӥ��U�q���ݥh�Q���s��, ���M�{�b�V����èS���j
���b�|, �i�O�Ӱ��Ȫ��H���٤���, �V���󹳭��[���t�a.
LONG
    );
 set("exits",([
               "north":__DIR__"inroom62",
                "east":__DIR__"inroom63",
                "west":__DIR__"inroom64",
               "south":__DIR__"inroom7",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
