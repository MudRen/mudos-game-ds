#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�n�L���");
set("long",@LONG
�o�̬O�n�䪺�L���, �A�i�H�ݴN���\�h�ӤH�����F�䲾
��, �ݨӪF��N�O�n�L��䪺�y�f.
LONG
    );
 set("exits",([ "north":__DIR__"seacoun39",
	       "east":__DIR__"seacoun42",
]));
  set("no_clean_up",0);
 set("outdoors","land");
 setup();
}            





