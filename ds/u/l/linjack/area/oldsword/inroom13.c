#include <room.h>
inherit ROOM;
void create()
{
 set("short","太玄道觀賓室");
 set("long",@LONG
雖然上次武林大會, 因為賽外烏日國入侵導致武林大會戰停,
但是太玄道觀仍然留了數名弟子在此等待進一步的消息, 好即時
趕回通報. 你眼前所見的正是太玄真人的三弟子--真衣道長「康真」
和兩名真衣道長的弟子.
LONG
    );
 set("exits",([ "south":__DIR__"inroom17",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
