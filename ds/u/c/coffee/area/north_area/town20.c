#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"村長家門口"NOR);
 set("long",@LONG
這裡是北蠻村村長家的大門，你沒想到村長家居然那麼
大，比一般的住宅大上三倍，你不禁想進去逛逛，但是隨便
進去真的好嗎？

LONG
    );

       set("exits",([
       "west":__DIR__"town13", 
       "east":__DIR__"town21",           ]));

        set("objects", ([
           ])); 
 set("outdoors","land"); set("no_clean_up", 0);
 setup();
}     


