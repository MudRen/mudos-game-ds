#include <ansi.h>
inherit NPC;
void create()
{
        set_name("小孩子" , ({ "child" }) );
        set("level",1);
        set("race","人類");
        set("gender","男性");
        set("dex",-1);
        set("age",6);
        set("long","他是一個全身髒兮兮的小孩。\n");
        set("inquiry/小路","哦？你是指上次，我們組的偵探隊所去的地方嗎？\n");
        set("inquiry/對","這條小路就在刀狂所在的地方，我勸你還是別去好了，裡頭極為兇險。\n");
        set("inquiry/是","這條小路就在刀狂所在的地方，我勸你還是別去好了，裡頭極為兇險。\n");
        set("inquiry/殭屍","這殭屍恐怖極了，見人就殺，我還差點死掉呢....@_@\n");
        setup();
        carry_object(__DIR__"wp/sword1.c")->wield();
}

