#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit __DIR__"muder.c";
void create()
{
 set("short",HIW"�F�_"NOR"�A�L"NOR"��"YEL"�d�h��"NOR);
 set("long",@LONG
����d�h�ϲ`�B, �o�̤ϦӨS���@�}�l�����ơA�h�A�a�ұa
�����h��, �]�]���ݦb���B�ɶ��[�F, �v���J�A. ���ۨ��ۡA�o
�{�X���f���b�Ѫŭ��R��, ���o�̪��f�����G�S�O�����P.
LONG);
 
 set("exits",(["north":__DIR__"en55",
               "south":__DIR__"en65",
               ]));
 set("objects",([__DIR__"npc/fly" : 4+random(4),
               ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        

