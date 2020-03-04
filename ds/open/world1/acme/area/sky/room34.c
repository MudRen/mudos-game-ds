// Room34.c

inherit ROOM;

void create()
{
        set("short","【天罡\堂】");
        set("long", @LONG
天地會在天下間分堂有數百，而其中最重要的兩大分堂就坐鎮在
總舵的所在。室內放著十多張大木椅，而且有一名老伯在打掃。而四
周佈置得一塵不染，就和大殿一樣，你想大概是眼前的老伯所整理的
吧，突然你心中一震，看到這老伯拿的是一柄精鐵打成的鐵掃帚，此
掃帚非常人可以拿起....你心中想著，【天罡堂】果然是臥虎藏龍之
地。

LONG
        );
        set("exits", ([
                "east": __DIR__"room35",
        ]));
        set("objects",([
//__DIR__"item/equip_shelf" :1,
__DIR__"item/weapon_box" :1, // 2006.5.30 add by whoami
//__DIR__"item/item_shelf" :1,
]));
        set("light",1);
        set("no_kill",1);
set("no_goto",1);
        setup();
        set("stroom",1);
}

