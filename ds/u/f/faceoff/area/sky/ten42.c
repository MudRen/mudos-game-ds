#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�C�۸�");
 set("long",@LONG
�C�۸����H���Pı�۷��X�@�A�ӧA�{�b�Ҩ����C�۸�
�O���U�s����V�A�]�N�O�q�_�ٮp��V�k���p�A���L�b�k��
�p���W���@�Ӥj���q�A�]���b�f�y�W�k���]���O�@�y�p�F�A 
�q�o�̩��F�i�H�쨺�����q�A�ө���h�|�^��_�ٮp....
LONG
    );
 set("exits",([  "eastup":__DIR__"ten43",
              "westup":__DIR__"ten5",
    ]));
 set("objects", ([__DIR__"npc/dog" : 2,
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
}


