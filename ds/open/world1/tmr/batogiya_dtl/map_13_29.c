#include <room.h>
inherit HOCKSHOP;
void create()
{
	set("short", "民宅");
        set("long", @LONG
這裡原本是個民宅，竟被私自設立為一處當舖，真在沒規矩。
LONG
);
	set("exits",([
	"north" : __DIR__"map_12_29",
	]));
        setup();
        set("map_long",0);     //show map as long
}

