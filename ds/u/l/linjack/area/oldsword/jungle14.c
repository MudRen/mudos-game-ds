#include <room.h>
inherit ROOM;
void create()
{
 set("short","�O�L��");
 set("long",@LONG
����o, �A���|�P�w�g�R���ۨ��Ǯ��ƤS�շt���s�n, �A�]�w
�g�i�H�������b�O�L���ݨ�e�̼ҽk���M�����v, �ݰ_�ӧA�w�g��
�J�I�ҤF, ���L�A�{�b���}�i���٨Ӫ���.
LONG
    );
 set("exits",([ "east":__DIR__"jungle15",
                "west":__DIR__"jungle13",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
