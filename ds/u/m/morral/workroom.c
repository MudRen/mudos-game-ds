#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
  set("short",HIC"楊威利的家中"NOR);
        set("long", @LONG
你來到了一個很優雅的房間，覺得楊威利在這過〝年金小偷〞
的日子，真是非常舒適.雖然時值夏日,不過氣候並不像季風
地帶的那樣潮濕暑熱.一陣陣的微風飄過林木之間,彷彿是加
有葉綠素和陽光的香水把人的皮膚洗的舒舒服服.
LONG
); // 長敘述
 set("exits", ([  //此房間連結之出口方向及檔案
    "luky" : "/u/l/luky/workroom",
"shengsan": "/u/s/shengsan/workroom",
"wiz": "/d/wiz/hall1",
"meet":"/open/world3/meetroom",
"arch":"/d/wiz/hall6",
//"iceland":"/u/m/morral/iceland/port1",
]));
set("light",1);
set("valid_startroom",1);  
set("no_fight",1);
set("no_magic",1);
set("objects",([
]));
        set("no_clean_up", 0);
setup();
        replace_program(ROOM);
}                                  
