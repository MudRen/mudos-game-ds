inherit ROOM;
void create()
{
 set("short","風雷堂");

 set("long",@LONG
這是明教存放防具、武器和道具的地方，架上琳瑯滿目的的防具
武器和各種珍奇異寶，令人眼花撩亂，這都是由風雷堂堂員等人
出生入死不惜犧牲生命所得來的，由於他們的努力，加上明教的
團結，明教才有今天這樣的成就。旁邊有人在整理架上的物品，
和管理。
LONG
    );
 set("exits",([ "up":"saintming",
"east":"darkfire",
    ]));
        set("no_kill",1);
        set("objects",([
__DIR__"item/eq_shelf" :1,
__DIR__"item/wp_shelf" :1,
__DIR__"item/item_shelf" :1,
]));
        set("light",1);
 setup();
        set("stroom",1);
}

