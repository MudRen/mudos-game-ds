inherit ROOM;

void create()
{
        set( "short", "地底神殿遺跡") ;
        set( "long", @LONG
偌大的房間中，擺滿了各式各樣的武器和盔甲，牆上的夜明珠發
出的光芒，和房中的物品相互輝映，在陽剛味極重的武器中，隱隱透
出一股攝人的威壓感，看來這裡的主人不是普通人物。
LONG
);
        set("exits", ([ /* sizeof() == 1 */
                  "south" : __DIR__"room-15",
        ]));
        set("objects",([
                   __DIR__"../npc/lieh_shen" : 1,
                 ]) );
        set("light",1);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        set("no_clean_up", 0);
        setup();
}

