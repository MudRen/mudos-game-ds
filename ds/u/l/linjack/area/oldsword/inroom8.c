#include <room.h>
inherit ROOM;
void create()
{
 set("short","����");
 set("long",@LONG
�o��O�V�����\�], ���X�Ӽp�l�M�e�檺�p���b���i���X,
ť���o�䥭�ɹ�~���]���}��, �i�H�Ӧ��R��L�p��Τ@������
�ѸѰ���, �Ӷ}��j�b��, �j�a�h�H���U�����߶}��Y��. �o��
���@�ǦU�a�Ӫ��ȤH�b�����}, �A��~�ݥh, �i�H�ݨ짧�[����
�����! ���\�h��B���b�C�C�����U�L�̤߷R�����.
LONG
    );
 set("exits",([ "down":__DIR__"inroom62",
               "north":__DIR__"garden1",
                "east":__DIR__"garden2",
               "south":__DIR__"garden3",
                "west":__DIR__"garden4",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
