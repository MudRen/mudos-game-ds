#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "�s�V�p�|");
  set("long", @LONG
�k��F���B�A�s�������W�i�@��̹D�C�u�۴̹D���W�s�A��
�F�����Q�����A�u���D���V����s���A�V�O�U���A�����]�V�O��
�V�����C�b�A�e���O�B�`�I�b�s�L�`�B������A�R�����a�A���O
�S���@���𮧡C
LONG
);
  set("exits", ([ 
  "south" : __DIR__"way05n",  
    "north" : "/open/world1/tmr/unquiet_manor/map_17_8",
]));
        set("outdoors","land");

        setup();
}

