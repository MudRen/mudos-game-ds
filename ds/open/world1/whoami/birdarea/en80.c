#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"�d�~"YEL"����"NOR);
 set("long",@LONG
�A�{�b���b�d�~�j�쪺��K�W, ���M���O��K, ���o�O�M��
�`����쪺��F�t���h��, �b�o��K�W���@�����j��������
�b�M�䭹��, �e�ݨӨ{�l�ܾj���ˤl.
LONG);
 
 set("exits",(["down":__DIR__"en70",
              ]));
 set("objects",([__DIR__"npc/godbird" : 1,
               ]));
 set("no_clean_up", 0);
 setup();
}        

