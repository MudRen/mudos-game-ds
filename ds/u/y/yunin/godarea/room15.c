#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"���Y"NOR);
        set("long", @LONG
�A�@�X���ө񺡼Ƨ�Z�����ж���A��ݨ�F�@���e�諸���D�A
���D���ⰼ���ƶ����ж��A�A�߸̤@�Q�A�̭����H���W��@�w���|
�p���~�ҥX���ж��D�H�C
LONG
 );       
        
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"room13",
  "west"  : __DIR__"room16", 
  "east"  : __DIR__"room17", 
  "southwest" : __DIR__"room18",]));  
        set("no_clean_up", 0);
        setup();
}     

