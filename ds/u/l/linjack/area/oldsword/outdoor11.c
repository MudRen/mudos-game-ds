#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s�D�U");
 set("long",@LONG
�A���b�@�Ӥs�D���U, �s�D�]���~�[����, �w�g�����C�a,
�ӥB�۶��g���j�B������w�g�ݯ}����, �]�S�����U���Y����
���άO���, �ݨӻ��\�����n���H�O�W���h��. �γ\�A�i�H��
�U�@�Ǹ˳ƨӳq�L�s�D.
LONG
    );
 set("exits",([ "south":__DIR__"outdoor9",
                "east":__DIR__"outdoor10",
                "northup":__DIR__"outdoor12",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}