#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�۫Τ�");
set("long",@LONG
�A�G���i�J�F�۫Τ�, �ߨ�o�{���@���R�����N�������q
�·t���g�X! �A�߸̤@��, �w�F�w����, ��~�o�{���@�Ө��F
�˪��C�Τj�~�צb��u�W, �ݨӦ��G���ǩǩǪ�....
LONG
    );
 set("exits",([ "out":__DIR__"seacoun27",
]));
set("objects", ([__DIR__"npc/yu" : 1,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
}            