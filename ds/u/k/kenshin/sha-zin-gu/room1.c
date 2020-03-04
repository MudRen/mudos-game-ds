inherit ROOM;

void create()
{
        set("short", "森林");
        set("long", @LONG
在這一遍草綠漫步的森林裡，不免讓人感到有點無力，但是前
方有一道光線，想必就是森林的出口了，據人民所示，前方就是前
武林少俠寧采和所住之處，名叫【暇日谷】。
LONG
        );
        set("current_light", 2);
        set("outdoors", "forest");
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room2",
  "north" : "/open/world1/cominging/area/river7",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

