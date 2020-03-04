// 山貓(adx) by snow 2000-05-15

inherit ROOM;

void create ()
{
        set ("short", "比武場大門");
        set ("long", @LONG
這裡是比武大會會場的大門，一座高高的木制牌坊，上書『比武
場』三個鑲金大字。這裡經常舉辦各種類型的比武大會。所有的人都
有機會參加，往東是滄縣城門，你也可以發現過往旅客不時往這望來
，似乎便有躍躍欲試的感覺。
LONG);
        set("no_fight",1);
        set("no_clean_up",1);
        set("exits", ([
                "north"   : __DIR__"zoulang",
                "east": "/open/world1/tmr/area/city-door",
        ]));
        set("objects", ([
                __DIR__"npc/gongping" : 1,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        object ob, where;

        if (!where=find_object(__DIR__"gate"))
                where=load_object(__DIR__"gate");
          if(!objectp(ob=present("da go ko", where)) ) return ::valid_leave(me,dir);

        if ( !wizardp(me) && dir=="north" ) {
                  if( ob->query("fangshi")!="single" )
                        return notify_fail("現在沒有任何比武，你不能進去。\n");
        }
        return ::valid_leave(me, dir);
}

