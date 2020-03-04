#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIG"眠之森林"NOR);
        set ("long", @LONG
呼！走了那麼遠的路，你慢慢感到不安，是前面
的城堡令你膽顫心驚嗎？，還是？....這裡四周雖然
草木仍然相當茂密，但是前方的路已經越來越大了。
LONG);  
        
        set("exits", ([
        "south": __DIR__"road2",
        "north": __DIR__"dragon1",
        ]) );
        set("objects", ([
        __DIR__"npc/dog" : 1,
        ]) );
        set("outdoors","workroom.c"); 
        setup();
        replace_program(ROOM);
}
