#include <room.h>
inherit ROOM;
void create()
{
 set("short","�ªZ�ͽþQ");
 set("long",@LONG
�o�̬O�V����ĤG�N�̤l���̰����h���̤l���ж�,
�o�ǤH�q�`�O�t�d����зs�i�v�̮v�f���H��, �Z�\����
�۷�������. �A�i�H�ݨ즳�|�ӤH�b�̭��𮧵�.
LONG
    );
 set("exits",([ "south":__DIR__"inroom46",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
