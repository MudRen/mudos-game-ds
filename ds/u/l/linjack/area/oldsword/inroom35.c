#include <room.h>
inherit ROOM;
void create()
{
 set("short","������");
 set("long",@LONG
��! �ѧo! �o�䪺�����i�u�}�G. �A���T�٤����f���s�F�_��. 
�J�Ӭݬݥ|�P�~�o�{����ӤH���b�o��﫳, �~��, �ഺ. �i�u��
��, �o��ӤH���G�����O�`�p, ��ջ�½�N�i�H�a���K�Ѥl, ����
����. �����w�L�̬O��b�U�����A�Ѽӳ�. �_���٦����Ѿ�.
LONG
    );
 set("exits",([ "down":__DIR__"inroom29",
               "north":__DIR__"inroom36",]));
 set("no_clean_up", 0);
 set("light", 1);
 setup();
 replace_program(ROOM);
}
