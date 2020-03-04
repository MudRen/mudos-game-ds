#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"地下墓穴"NOR);
        set("long", @LONG 
突然憑空出現一團碧綠的磷火，忽上忽下緩緩地飄移，試圖趕走
這裡的人，突然又憑空不見了，嚇的你面無表情，一心只想離開這。
這裡的神秘人好像都不怕鬼怪的。
LONG
        );
        set("exits", ([ /* sizeof() ==  */
  "northeast" : __DIR__"room2",]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/neck-guard" : 1,
]));
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


