#include <room.h>
inherit ROOM;
void create()
{
 set("short","�Ѿ�����");
 set("long",@LONG
�g�L�F�m�\�𪺤Ѿ�, �A�Ө�F�o�̪��Ѿ�����, ���k
���@�ӥ��O�i�H��, ���O�S�����i�H�A���e���U�h. �a�O�W
���G�i�H�ݥX�@�Ӥ�ι���, �����D�O�Ӥ���F��, �ݰ_��
���޲���.
LONG
    );
 set("exits",(["east":__DIR__"inroom59",
               "west":__DIR__"inroom60",
               "south":__DIR__"inroom57",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
