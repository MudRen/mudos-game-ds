#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit __DIR__"muder.c";
void create()
{
 set("short",HIW"�F�_"NOR"�A�L"NOR"��"YEL"�d�h��"NOR);
 set("long",@LONG
�A�j�ԵۥO�H���ߪ�����|�B���F��, �V�|�P��h, ��M�o
�{�F�n�X����e�A���ӬO�b���B�g�������H, �����D�쥨�Ϊ���
����, �үd�U��. �b�t�B�o�{�F�X���A�q���ݹL�����j����, ��
�b�٭��a�W���հ�, �򰩮��M���Pı����W���Y.
LONG);
 set("exits",(["west":__DIR__"en53",
               "southwest":__DIR__"en57",
               "southeast":__DIR__"en59",
               ]));
 set("objects",([__DIR__"npc/bug" : 2+random(3),
               ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        

