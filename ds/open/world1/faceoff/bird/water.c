#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"天梟聖泉"NOR);

 set("long",@LONG
這裡就是聞名藥界的天梟聖泉, 傳說這是一個善人重病之
時, 有神仙在夢中指引此泉, 此人將泉水引回家後, 每日飲兩
瓢, 病情漸趨穩定而終至痊癒, 從此天梟聖泉就成為採藥者的
取水所必定之地, 尉遲妄退出天梟之前, 曾立下重誓要殺盡天
梟之採藥者, 因此霸佔此泉, 天梟攻丹一派也從此不再見於此
處....
LONG
    );
 set("exits",([ "south":__DIR__"bird6",
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}
