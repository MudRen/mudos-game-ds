inherit ROOM;
void create()
{
 set("short","風雷堂");
 set("long",@LONG
這是明教存放防具、武器和道具的地方，架上琳瑯滿目的的防具
武器和各種珍奇異寶，令人眼花撩亂，這都是由風雷堂堂員等人出生
入死不惜犧牲生命所得來的，由於他們的努力，加上明教的團結，明
教才有今天這樣的成就。旁邊有人在整理架上的物品，和管理。
LONG
    );
 set("exits",([ "up": __DIR__"saintming",
"east": __DIR__"darkfire",
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
