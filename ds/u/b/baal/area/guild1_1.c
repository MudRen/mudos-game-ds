#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"天鷹石室"NOR);

 set("long",@LONG
這裡在走廊的照耀下, 就顯的陰暗多了, 不過, 這裡卻相當涼爽和寧
靜首先引起你注意的, 是掛在牆上叮叮噹噹響震天的匕首和藥鋤, 接著,
才是其他劍, 刀一類的武器, 牆上所掛的匕首都被擦的油油亮亮, 在油燈
的照射下放出精亮的光芒, 藥鋤雖擦洗的相當乾淨, 仍有一股藥味散發出
來, 角落有幾個穿著採藥裝束的教徒, 正在尋找自己採藥的用具.   
LONG
    );
 set("exits",([ "north":__DIR__"guild1", 
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

