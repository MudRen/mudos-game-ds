#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"�F�_"NOR"�A�L");
 set("long",@LONG
�A���_���F�L��, ���񪺾���٬O�@�˪��Z�K, ���O�A����
�����a���h, �o�Q�s�s���k������¶, �o���p�����F�詵���X
�h.
LONG);
 set("exits",(["south":__DIR__"en75",
               "east":__DIR__"en78",
               ]));
 
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}
