#include <room.h>
inherit ROOM;
void create()
{
        set("short", "搭車處");
        set("long", @LONG
看著這裡來來往往的人群，跟剛剛空無一人的城市簡直是有著天壤之
別，大家手上都大包小包的礦石，看來是要拿回家當裝飾的，一位列車長
正在催促大家快點離開了，不要在在這裡阻礙交通，大家都依依不捨地看
了一下這個地方，接著一輛輛的高速列車便將他們接走了。
( 提示: use ticket 。 )
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));

        setup();
        replace_program(ROOM);

}


