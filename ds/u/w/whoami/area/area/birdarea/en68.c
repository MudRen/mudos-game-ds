#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit __DIR__"muder.c";
void create()
{
 set("short",HIW"�F�_"NOR"�A�L"NOR"��"YEL"�d�h��"NOR);
 set("long",@LONG 
�b�o�@�j���d�h�a��, �A��M�o�{�@�p��������, �_�X�}�}
���u��, �ϧA���W�C�U�Y�h�Z���@�f, �M�D�������H���M��n
. �����䪺�d�~���쥿�b�����K�K�s��, �a�Ӥ@�ѥͮ�.
LONG);
 set("exits",(["west":__DIR__"en67",
               "southeast":__DIR__"en71",
               ]));
 set("objects",([__DIR__"npc/tfrog" : 3+random(3),
               ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        

