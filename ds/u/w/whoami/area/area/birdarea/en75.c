#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"�F�_"NOR"�A�L");
 set("long",@LONG
�A���F�_���F�L��, �A�ݤF�ݥ|�P, ���F���`�����j���H
�~, ����]�S��, �A�Pı��o�����V�ӶV�p, �n���֨���p����
���Y�F.
LONG);
 
 set("exits",(["southwest":__DIR__"en74",
               "north":__DIR__"en76",
               ]));
 
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        

