#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s�U�D�������Y");
 set("long",@LONG
���w���a�Τw�g�즹����F, �A�ӴN�O�W�s�����q, ����s��
�����@�����Ȧ�G��, ���M���h�C��ӱ���F, �L�k���먺�O����
�F��. ���F���N�O��F�D�n�D�������I.
LONG
    );
 set("exits",([ "northwest":__DIR__"mountdown5",
                "east":__DIR__"mountdown7",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
