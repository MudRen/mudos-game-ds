#include <ansi.h>
inherit NPC;

void create()
{
        set_name("李按",({ "lee an","an","lee" }) );
        set("long",@LONG
北蠻村一向是製作帳篷而聞名，李按更是村中的佼佼者，所
做出的帳篷舒適又堅固耐用，在酷寒的山頭上使用起來，更是給
人帶來舒適及莫名的情素愫。
LONG
);
        set("race","人類");
        set("age",30);
        set("level",10);
        set("attitude","friendly");
        setup();                
}

