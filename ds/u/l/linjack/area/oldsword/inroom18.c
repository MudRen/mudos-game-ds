#include <room.h>
inherit ROOM;
void create()
{
 set("short","�j���D");
 set("long",@LONG
�o��N�O�V�����R�L�񪺤j���D, �e�F��V, �a�W�Q��
�C�Ŧ⦳�ն��᯾���a��. ���k���䱾�F�ܦh�r�e, �A�ݤF�@
��, �o�X���r�e���O�A�������L��. ť���O�L�̰�D�ۤv�D��
�O! ���k��Ǧ��X�W�ͽéM�����M�A�D�n.
LONG
    );
 set("exits",([ "north":__DIR__"inroom7",
                "south":__DIR__"outroom1",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}