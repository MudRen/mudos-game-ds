#include <room.h>
inherit ROOM;
void create()
{
 set("short","�Ѿ�");
 set("long",@LONG
�q�L�m�\���, �Ө�F�@���Ѿ��W��. �o�����V����
���b��ٽu�٦��@�q�Z��. ���O�]�Q������F, ���k�����
�i�H�ݨ���ӥ~���γ����. �q�o�Ө��פ]�i�H�����ݨ�V
�����~���j�z���a.
LONG
    );
 set("exits",(["north":__DIR__"inroom58",
               "south":__DIR__"inroom56",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
