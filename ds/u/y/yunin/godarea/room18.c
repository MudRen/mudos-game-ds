#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"走廊盡頭"NOR);
        set("long", @LONG
慢慢的走在著個寬闊的走廊上，心裡只有一個疑問，這個是哪裡
，裡面的擺設，跟現實社會裡大有差意，雖然整齊，但整齊中卻帶有
點玄機，想著想著，就不知不覺走到了盡頭了!!
LONG
 );       
        
  set("exits", ([ /* sizeof() == 2 */
  "northeast"  : __DIR__"room15",
  "down" : __DIR__"room19",
  
]));  
        set("no_clean_up", 0);
        setup();
}     


