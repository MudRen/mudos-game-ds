#include <room.h>
inherit ROOM;
void create()
{
 set("short","�L���x�ë�");
 set("long",@LONG
�o��O�V���󤤥D�n���L���x�ë�, �̭����n�X������
���b��W, �o�䪺�L�����M������Q����}, ���L�]�٬O��
���L�h��! ���@�ӱM���ݺ޳o�̪��u�å����b�ӱ�f.
LONG
    );
 set("exits",([ "up":__DIR__"outroom2",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}