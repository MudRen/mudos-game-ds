#include <ansi.h>
inherit NPC;
void create()
{
    set_name("杜漢",({"Michael Doohan","michael","doohan"}));
    set("long",@LONG
《車神》杜漢，一個響鐺鐺的名字，同道中人聽到他的名字沒有不起
立敬禮的。他是WGP 500 '94~'98 世界冠軍。

生日：1965年6月4日

LONG);
    set("level",45);
    set("title","飆車族");
        set("age",35+random(2));
    set("combat_exp",50000);
    set("nickname","[0;1;31m�[1m�[1m�[1m�[0m");
        setup();
carry_object(__DIR__"eq/arai_pants_17")->wear();
carry_object(__DIR__"eq/arai_shield_14")->wear();
carry_object(__DIR__"eq/arai_surcoat_10")->wear();
}
