#include <room.h>
inherit ROOM;
void create()
{
 set("short","���۪��U");
 set("long",@LONG
�A�{�b���b�V����e���@�ӥ��j�۪�, �ݰ_�ӦV�O�@�y�p
����, �٬O���[. �۪��W�U�����F�ƦW�ͽ�, �u�ƴ��Y. �o��
�O�۪����谼, ���@���ӱ�i�H���W����۪����W, ���誺��
�V�٦��q��, ���L�n�q�۪��W�~��q�F.
LONG
    );
 set("exits",([ "east":__DIR__"outdoor1",
                "up":__DIR__"outdoor6",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}