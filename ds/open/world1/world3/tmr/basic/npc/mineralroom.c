inherit ROOM;

void create()
{
        seteuid(getuid(this_object()));
        set("short","礦石集中營");
        set("long","一個專門存放礦石的地路。\n");
        set("light",1);
        set("no_clean_up",1);
        setup();
}


