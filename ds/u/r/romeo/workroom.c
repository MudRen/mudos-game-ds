#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�Ѷ��~");
        set("long", @LONG
�o�̥u���@�y�J���C
LONG
        );
        
       set("exits", ([ /* sizeof() == 1 */
 "west" : "/d/wiz/entrance",
        ]) );

  set("light", 1);

  setup();
}

void init()
{

 if( !wizardp(this_player()) )
 {
  write(HIR" �o�̤��O���a�i�i�J���a�� !!! ���Ȩt�Φ۰ʰh�X���a !!! "NOR);
  this_player()->move(__DIR__"bug");
 }
}
