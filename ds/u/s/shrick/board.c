#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name("中央廣場佈告欄",({"board"}));
        set("location","/u/s/shrick/rooms/center.c");
        set("board_id", "center_b");
        set("long",
        "這是猶羅村中央廣場上所放置的佈告欄，
         海賊們貼上自己傳奇驚險的故事給往來的
         與其他海賊們一同分享。\n");
        setup();
        set("capacity",100);
        replace_program(BULLETIN_BOARD);
}
