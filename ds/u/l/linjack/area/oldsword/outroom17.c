#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s���U��");
 set("long",@LONG
�o��N�O�@�B�s�����U��, �A���W��, ��Ӥs���D�`
�D�`�����q, �o��u���Z���ϧA�L�k�ݲM����Ӥs������
��. ���L�����ܲʪ��ý����b�o, ���ӥi�H���U�A���W�h,
���O�d�U�o�p�ߤ~��.
LONG
    );
 set("exits",([ "south":__DIR__"outroom16",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
