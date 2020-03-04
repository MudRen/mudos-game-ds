#include <room.h>
inherit ROOM;
void create()
{
 set("short","山縫之中");
 set("long",@LONG
通過了三名守衛, 你來到一個山縫之中, 這邊長滿了
你毫無聽聞的神奇花草, 長相也十分奇特, 但是裡面有三
四名身穿藍衣的神秘人物正對你兇狠的看著, 他們似乎是
負責照顧這裡的人, 你最好快點離開. 這邊三面都是山壁
讓人很難發現這裡.
LONG
    );
 set("exits",(["south":__DIR__"garden1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
