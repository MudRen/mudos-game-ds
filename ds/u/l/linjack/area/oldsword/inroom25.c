#include <room.h>
inherit ROOM;
void create()
{
 set("short","����N��");
 set("long",@LONG
�A�@�i�ӳo�̴Nť��X�Ӧ�����H��ᦳ�����w�ۦ�g, ��W��
�Ƕ����٨S�Y��, ���L���X���A�l�b�W����, �j���O��w�g�o�ĤF�a.
�|�P���Q���W��g�M��, ��Ӫ��\���~���������F, �ӧA���e���o
�X�W�k�v, ��ۤ��P�󤤤g, �j���O��~�L�Ӫ��a.
LONG
    );
 set("exits",(["south":__DIR__"inroom16",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
