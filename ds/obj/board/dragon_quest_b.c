#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
        set_name(HIG"狂龍幫解謎板"NOR, ({ "quest board", "board" }) );
        set("location", "/open/world1/cominging/area/dragon/fire_dragon");
        set("board_id", "dragon_quest_b");
        set("long",
        "這是一個供幫眾們解迷用的留言板。\n");
        setup();
        set("capacity", 99);
        set("master",({"andygi"}));
}
