#include <ansi.h>
inherit MOBROOM;
void create()
{
        set("short", "競技場老鳥區");
        set("long", @LONG
你一進來就看到許多熟悉的野生猛獸和一些不知名的怪物，大概是
競技場特地去邊疆或荒郊野外上山所捕獲的動物抓回來給冒險者訓練武
功，在怪物旁還有一些手銬銬住牠，以防止其四處遊走妨礙他人，在南
邊是競技場的大廳，如果你需要休息可以到那喝杯水或吃上一餐。
LONG
        );
        set("exits", ([  "south" : __DIR__"level20", ]));
        set("no_clean_up", 0);
        set("outdoors","land");
        
// /*
        // Mob Room Settings
        set("chance",100);
        set("mob_amount", 4);
        set("mob_object",({
  __DIR__"npc/mtiger",
  __DIR__"npc/rdragon",
}));
// */
        set("outdoors","land");
        set("light",1);
        setup();
}

int valid_leave(object me, string dir)
{
	if( dir == "south" )
                tell_room(environment(me),me->name()+"往競技場大廳揚長而去。\n",({ me }));
        return ::valid_leave(me, dir);
}

