#include <ansi.h>
inherit NPC;
void create()
{
 set_name("重傷的旗主",({"leader",}));
 set("long",@LONG
一個山寨的旗主, 他看來受傷不輕.....
LONG
    );
 set("attitude", "aggressive");
 set("age",40);
 set("gender","男性");
 set("level",1);
 set("hp",1);
 set("con",1);
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
 carry_object(__DIR__"obj/flag");

}
