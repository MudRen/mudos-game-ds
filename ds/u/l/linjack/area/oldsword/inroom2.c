#include <room.h>
inherit ROOM;
void create()
{
 set("short","��D�ҤH���");
 set("long",@LONG
�o�����ӬO�V����D���ҤH���, �̭����\�]�u�O����
���R, ����ģ�����F�褣�p���, ���M��D�ҤH�w�g�h�@�@
�~�h�F, ���O�o�өж����M�O�s���Q������, �i�H���D��D
��ҤH���ΤߤF.
LONG
    );
 set("exits",([
               "west":__DIR__"inroom1",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
