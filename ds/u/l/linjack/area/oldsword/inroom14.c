#include <room.h>
inherit ROOM;
void create()
{
 set("short","�ѤѬ�����");
 set("long",@LONG
�o��N�O�ѤѬ��b�V���󪺻��ǤF, �ѤѬ����H�j�����ӲߺD
�o�䪺�\�], ��\�h�~�~�����M�˹��~�����F�_��, �ﱾ�F�@���~
�֩M�y�M�������F��. �A�ݨ�o�өж��̥u���@�ӤM�Ȧb�𮧵�,
�γ\�A�i�H�ݥL�o�ͤF�����.
LONG
    );
 set("exits",([ "north":__DIR__"inroom17",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
