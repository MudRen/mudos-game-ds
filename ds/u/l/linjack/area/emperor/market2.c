#include <room.h>
inherit ROOM;
void create()
{
 set("short","防具鋪聚集地");
 set("long",@LONG
原來這邊是皇城東北方十分出名的防具集散地, 城裡許多商店
的物品來源都是由此地而來, 你也能看到許多旅客或江湖人士在這
邊挑東挑西的. 一般江湖人行走江湖路的裝備, 這邊是應有盡有,
雖然沒啥好貨, 不過絕對足夠供應你初步的需求. 皮甲, 靴, 手套
, 脛甲, 甚至盔, 盾等等不常用到的防具你在這都能買到.
LONG
    );
 set("exits",([ "northwest":__DIR__"market3",
                "north":__DIR__"center",
                "northeast":__DIR__"road6",
                "south":__DIR__"road2_2"]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}