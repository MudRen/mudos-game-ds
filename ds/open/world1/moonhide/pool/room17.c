#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "���H�P�}");
        set("long", @LONG
�b�o�̡A�p�Ӭy�b�򩥹��U�`�`���e���A�ϱo�o�̪��a���A��
�Ǥ񤤶����A��誺�����B�A��n�ۤj�q���h�A�\�h�p�ͪ����E��
�b���̡C
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"room20",  
  "east" : __DIR__"room14",
  "north" : __DIR__"room16",])); 
        set("objects",([ /* sizeof() == 1*/
  __DIR__"npc/la-ah":1,
  __DIR__"npc/bu-la-fish":2,
]));        set("no_clean_up", 0);

        setup();
}

