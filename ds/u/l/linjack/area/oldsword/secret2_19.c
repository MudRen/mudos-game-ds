#include <room.h>
inherit ROOM;
void create()
{
 set("short","�q�D����");
 set("long",@LONG
�z, �u�O�@�������d�j��, �o�U�l�i�n�F, �o�䳣���n��, �ӥB
��W�G���C�a, ���\�A�n���H�����ӥi��q�o�̦A���^�W��, �]����
�~�S���i�H���ۤO���a��, �ݨӧA�u�n�b�o��t�M�X���F.
LONG
    );
 set("exits",([ "out":__DIR__"secret1_4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
