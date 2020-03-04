#include <room.h>
inherit ROOM;
void create()
{
 set("short","雜貨鋪聚集地");
 set("long",@LONG
原來這邊是皇城東北方十分出名的雜貨集散地, 城裡許多商店
的物品來源都是由此地而來, 你也能看到許多旅客或江湖人士在這
邊挑東挑西的. 不過這邊賣的大都是生活必需品, 食物和水, 一般
藥物, 藥材, 原料, 和一些雜七雜八的東西, 在這邊大都買得到,
而且還算便宜, 但是好料容易先被別人搶先, 因此要買真正的高級
品或許在這邊是找不到的.
LONG
    );
 set("exits",([ "southwest":__DIR__"market3",
                "south":__DIR__"center",
                "southeast":__DIR__"road6"]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}