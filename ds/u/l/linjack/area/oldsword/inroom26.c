#include <room.h>
inherit ROOM;
void create()
{
 set("short","�K��������");
 set("long",@LONG
�o��N�O�̪�~�}�l�����W�n�j���_�Ӫ��K��������, ���䪺
��W���F�X��u�j�u��, �j�ܤW�\�]���٨S���ʹL, �̭��u����W
�K�������̤l�b����, �L�̹�o�����Ҧ��G���O�ܺ��N. ��W�\
�F�@�ǰs��M�X����.
LONG
    );
 set("exits",(["north":__DIR__"inroom16",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
