#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�ϸz�D");

 set("long",@LONG
�o�̤w�g����F�ϸz�D������, �A���T�P�F�f��, �ש�i�H
�q�o���p�p�p���X�h�F, �N�b�A�y������, ���M�ݨ��@�Ӥɵ���
�����b���b�A����, �]�\�O�j�s���~��....
LONG
    );
 set("exits",([ "northwest":__DIR__"ten9",
                "northeast":__DIR__"ten11",
    ]));
 set("objects", ([__DIR__"npc/wind_ranger":2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}

