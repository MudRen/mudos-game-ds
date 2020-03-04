inherit ROOM;

void create()
{
        set("short", "孟村廟");
        set("long", @LONG
這是一間位於孟村村角的一間小廟，大門上漆著雄武的門神，廟裡供
奉著三尊神像之外，還擺置著一張神桌及一鼎香爐，只見桌上放滿了鮮花
、素果等祭祀的物品，爐中香火所散出的煙更是縈繞不絕。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "south" : __DIR__"vroad3",
        ]));
        set("objects",([
    __DIR__"npc/old-man":1, 
    //__DIR__"npc/thief_master":1,
        ]) );
        set("light",1);
        set("no_clean_up", 0);
        setup();
}
