#include <room.h>
inherit ROOM;
void create()
{
 set("short","�Ѿ�����");
 set("long",@LONG
�o��O�Ѿ�������, ���k�U�٦��@�ӥ��x�i�H���L�h. �o��
���a�W���ө_�Ǫ���ι���, �����D������t�q. �ӥB�o�䳺�M
�������������@�ç�u���B, �ݨӳo���˦��ǥȾ�....
LONG
    );
 set("exits",(["south":__DIR__"inroom36",
               "east":__DIR__"inroom38",
               "west":__DIR__"inroom39",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
